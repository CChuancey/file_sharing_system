#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__ 

#define BUFFSIZE 1024

typedef struct {
    int sock_fd;//
    int epollfd;
    char buf[BUFFSIZE];

    //待添加

}http_request_t;

typedef struct{

}http_response_t;

void init_http_request(int sockfd,int epollfd,http_request_t* request);
void* parse_http_request(void *);

#endif
