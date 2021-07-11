#include "epoll.h"

int setnonblocking(int fd){ //设置为非阻塞的fd
    int preStatusFlags = fcntl(fd,F_GETFL);
    int newStatusFlags = preStatusFlags | O_NONBLOCK;
    fcntl(fd,F_SETFL,newStatusFlags);
    return preStatusFlags;
}

void addfd(int epollfd,int fd,int enable_et){
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = fd;
    if(enable_et) event.events |= EPOLLET;
    if(epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event)==-1) exitErr("epoll_ctl()");
    setnonblocking(fd);
}

void et(int epfd,int listenfd,int nums,struct epoll_event ready_events[]){
    char buf[BUFFSIZE];
    for(int i=0;i<nums;i++){
        int fd = ready_events[i].data.fd;
        if(fd==listenfd){ //有连接请求
            struct sockaddr_in cliendSockAddr;
            socklen_t len = sizeof(cliendSockAddr);
            int clientSockfd = accept(listenfd,(struct sockaddr*)&cliendSockAddr,&len);
            assert(clientSockfd!=-1);
            puts("one client connected!");
            addfd(epfd,clientSockfd,1);
        }else if(ready_events[i].events&EPOLLIN){ //et模式下不会重复触发
            while(1){
                memset(buf,0,sizeof(buf));
                int ret = recv(fd,buf,BUFFSIZE,0);
                if(ret<0){
                    if(errno==EAGAIN||errno==EWOULDBLOCK){//通常EAGIN=EWOULDBLOCK,没有数据可读了
                        puts("read later");
                        break;
                    }else if(ret==0){
                        close(fd);
                    }else {
                        printf("gets %d bytes content: %s \n",ret,buf);
                    }
                }
                puts(buf);
                send(fd,buf,strlen(buf),0);
            }
        }
    }
}

