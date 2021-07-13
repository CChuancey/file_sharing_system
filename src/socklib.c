#include "socklib.h"

int init_server_socket(int portnum,int backlog) {
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1) return -1;
    struct sockaddr_in serAddr;
    bzero(&serAddr,sizeof(serAddr));
    serAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serAddr.sin_port=htons(portnum);
    serAddr.sin_family=AF_INET;
    int on=1;
    if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))==-1) return -1;
    if(bind(sockfd,(struct sockaddr*)&serAddr,sizeof(serAddr))==-1) return -1;
    if(listen(sockfd,backlog)==-1) return -1;
    return sockfd;
}



