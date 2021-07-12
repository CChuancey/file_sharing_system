#include "http_request.h"
#include <string.h>

void init_http_request(int sockfd,int epollfd,http_request_t* request){
    request->sock_fd = sockfd;
    request->epollfd = epollfd;
    memset(request->buf,0,sizeof(http_response_t));
    //待添加
}

void* parse_http_request(void* arg){

}
