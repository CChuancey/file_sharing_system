#include "http_conn.h"
#include <string.h>
#include <errno.h>
#include "epoll.h"

const char* ok_200_titile = "OK";
const char* error_400_titile = "Bad Request";
const char* error_400_form = "Your request has bad syntax or is inherently impossible to satisfy.\n";
const char* error_403_titile = "Forbidden";
const char* error_403_form = "You do not have permission to get file from this server.\n";
const char* error_404_titile = "Not Found";
const char* error_404_form = "The requested file was not found on this server.\n";
const char* error_500_titile = "Internal Error";
const char* error_500_form = "There was an unsual problem serving the requested file.\n";

const char *doc_root = "../doc";


void init_http_request(int sockfd,int epollfd,http_request_t* request){
    request->sock_fd = sockfd;
    request->epollfd = epollfd;
    memset(request->m_read_buf,0,sizeof(http_response_t));
    //待添加
    request->m_read_idx=0;
    request->m_check_idx=0;
    request->m_start_line=0;
    request->check_state=CHECK_STATE_REQUESTLINE;
}

void close_conn(http_request_t* request){
    if(request->sock_fd!=-1){
        removefd(epfd,request);
        free(request);
    }
}

int read_buf(http_request_t* request){
    if(request->m_read_idx>=READ_BUFFSIZE){
        //缓冲区不足，关闭连接,待优化-------------：写成循环缓冲
        fprintf(stderr,"buffer size is not enough!\n");
        close_conn(request);
        return -1;
    }
    while(1){
        int bytes_read = recv(request->sock_fd,request->m_read_buf+request->m_read_idx,READ_BUFFSIZE-request->m_read_idx,0);
        if(bytes_read==-1){
            if(errno==EAGAIN||errno==EWOULDBLOCK){
                break;
            }
            //读缓冲出错！
            close_conn(request);
            return -1;
        }else if(bytes_read==0){
            return -1;
        }
        request->m_read_idx+=bytes_read;
    }
    return 0;

}

char* get_line(http_request_t* request){
    return request->m_read_buf+request->m_start_line;
}

//从状态机
LINE_STATUS parse_line(http_request_t* request){
    for(;request->m_check_idx<request->m_read_idx;++(request->m_check_idx)){
        char tmp = request->m_read_buf[request->m_check_idx];
        if(tmp=='\r'){
            if(request->m_read_idx+1==request->m_read_idx) return LINE_OK;
            else if(request->m_read_buf[request->m_check_idx+1]=='\n'){
                request->m_read_buf[request->m_check_idx++]='\0';
                request->m_read_buf[request->m_check_idx++]='\0';
                return LINE_OK;
            }
        }else if(tmp=='\n'){
            if(request->m_check_idx>1&&request->m_read_buf[request->m_check_idx-1]=='\r'){
                request->m_read_buf[request->m_check_idx-1]='\0';
                request->m_read_buf[request->m_check_idx++]='\0';
                return LINE_OK;
            }
            return LINE_BAD;
        }
    } 
}

//获取请求方法(GET、POST) 以及url
HTTP_CODE parse_request_line(http_request_t* request,char* text){
    request->m_url = strpbrk(text," \t"); 
    if(request->m_url==NULL) return BAD_REQUEST;
    *request->m_url++ = '\0';
    char* method = text; //m_url为请求头余下的所有字符串
    if(strcasecmp(method,"GET")==0){
        request->m_method = method;
    }else return BAD_REQUEST;
    request->m_url+=strspn(request->m_url," \t");
    request->m_http_version = strpbrk(request->m_url," \t");
    if(request->m_http_version==NULL) return BAD_REQUEST;
    *request->m_http_version++ = '\0';
    // if(strcasecmp("HTTP/1.1",request->m_http_version)!=0) return BAD_REQUEST;
    /*
       request->request_headers = strpbrk(request->m_http_version," \n");
       if(request->request_headers==NULL) return BAD_REQUEST;
     *request->request_headers++='\0';*/
    // puts(request->m_http_version);
    if(strncasecmp(request->m_url,"http://",7)==0) {
        request->m_url+=7;
        request->m_url = strchr(request->m_url,'\\');
    }
    if(request->m_url[0]!=47) return BAD_REQUEST;       //此处需要研究，如果写成if(request->m_url[0]!='\\') 条件为真！！！
    //puts(request->m_url);
    request->check_state = CHECK_STATE_HEADER; //有限状态机 
    return NO_REQUEST;
}

HTTP_CODE parse_headers(http_request_t* request,char* text){
    if(text[0]=='\0'){
        if(request->m_content_length!=0){
            request->check_state=CHECK_STATE_CONTENT;
            return NO_REQUEST;
        }
        return GET_REQUEST;
    }else if(strncasecmp(text,"Connection:",11)==0){
        text+=11;
        text+=strspn(text," \t");
        if(strcasecmp(text,"keep-alive")==0){
            request->m_linger=1; //keep alive
        }
    }else if(strncasecmp(text,"Content-Length:",15)==0){
        text+=15;
        text+=strspn(text," \t");
        request->m_content_length = atol(text);
    }else if(strncasecmp(text,"Host:",5)==0){
        text+=5;
        text+=strspn(text," \t");
        request->m_host = text;
    }
}

HTTP_CODE parse_content(http_request_t* request,char* text){
    if(request->m_read_idx>=(request->m_content_length+request->m_check_idx)){
        text[request->m_content_length]='\0';
        return GET_REQUEST;
    }
    return NO_REQUEST;
}

HTTP_CODE process_read(http_request_t* request){
    LINE_STATUS line_status = LINE_OK;
    HTTP_CODE http_code = NO_REQUEST;
    while(((request->check_state==CHECK_STATE_CONTENT)&&(line_status==LINE_OK))||(line_status=parse_line(request))==LINE_OK){
        char* text = get_line(request);
        request->m_start_line = request->m_check_idx;

        switch(request->check_state){
        case CHECK_STATE_REQUESTLINE:
            http_code = parse_request_line(request,text);
            if(http_code==BAD_REQUEST) return BAD_REQUEST;
            break;

        case CHECK_STATE_HEADER:
            http_code = parse_headers(request,text);
            if(http_code == BAD_REQUEST) return BAD_REQUEST;
            break;

        case CHECK_STATE_CONTENT:
            //检查请求体是否被完整
            http_code = parse_content(request,text);
            if(http_code==GET_REQUEST) return do_request(request);
            line_status=LINE_OPEN;
            break;

        default:
            return INTERNAL_ERROR;
        }

    }
    printf("Host:%s\nConnection:%d\nConten_length:%d\n",request->m_host,request->m_linger,request->m_content_length);
    return NO_REQUEST;
}

//有限状态机解析
void parse_http_request(void* arg){
    http_request_t* request = (http_request_t*)arg;
    puts("thread is reading data");
    if(read_buf(request)==0){ //读进缓冲区
        puts(request->m_read_buf);
        HTTP_CODE code = process_read(request);
    }else{
        puts("read err");
        return; //请求读出错直接结束
    }
}


HTTP_CODE do_request(http_request_t* request){
    puts("do request");
}
