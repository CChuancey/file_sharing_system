#include "socklib.h"

int init_server_socket(int portnum,int backlog) {
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1) return -1;
    struct sockaddr_in serAddr;
    int ret = inet_pton(AF_INET,"127.0.0.1",&serAddr.sin_addr);
    if(ret==0){
        fprintf(stderr,"src does not contain a character string repre‐\
       senting  a  valid network address in the specified address family\n");
        exit(EXIT_FAILURE);
    }else if (ret==-1) exitErr("inet_pton()");
    serAddr.sin_port=htons(portnum);
    serAddr.sin_family=AF_INET;
    int on=1;
    if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))==-1) return -1;
    if(bind(sockfd,(struct sockaddr*)&serAddr,sizeof(serAddr))==-1) return -1;
    if(listen(sockfd,backlog)==-1) return -1;
    return sockfd;
}



