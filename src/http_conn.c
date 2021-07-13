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

HTTP_CODE parse_request_line(http_request_t* request){
    char* text = request->m_read_buf;
    request->m_url = strpbrk(text,"\t"); 
    if(request->m_url==NULL) return BAD_REQUEST;
    puts("request is parsing!");

}

void parse_http_request(void* arg){
    http_request_t* request = (http_request_t*)arg;
    puts("thread is reading data");
    if(read_buf(request)==0){ //读进缓冲区
        puts("read ok");
        puts(request->m_read_buf);
        //HTTP_CODE code = parse_request_line(request);        
    }else{
        puts("read err");
        return; //请求读出错直接结束
    }
}
