#include "epoll.h"
#include "thread_pool.h"
#include "http_request.h"

int setnonblocking(int fd){ //设置为非阻塞的fd
    int preStatusFlags = fcntl(fd,F_GETFL);
    int newStatusFlags = preStatusFlags | O_NONBLOCK;
    fcntl(fd,F_SETFL,newStatusFlags);
    return preStatusFlags;
}

void addfd(int epollfd,http_request_t* request,int enable_et){
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.ptr = (void*)request;
    int fd = request->sock_fd;
    if(enable_et) event.events |= EPOLLET;
    if(epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event)==-1) exitErr("epoll_ctl()");
    setnonblocking(fd);
}

void et(int epfd,int listenfd,int nums,struct epoll_event ready_events[]){
    char buf[BUFFSIZE];
    for(int i=0;i<nums;i++){
        http_request_t* requst = (http_request_t*)ready_events[i].data.ptr;//为了携带其他数据,弃用fd采用ptr
        int fd = requst->sock_fd;
        if(fd==listenfd){ //有连接请求
            struct sockaddr_in cliendSockAddr;
            socklen_t len = sizeof(cliendSockAddr);
            int clientSockfd = accept(listenfd,(struct sockaddr*)&cliendSockAddr,&len);
            assert(clientSockfd!=-1);
            puts("one client connected!");
            http_request_t* client_request = (http_request_t*)malloc(sizeof(http_request_t));
            init_http_request(clientSockfd,epfd,client_request);
            addfd(epfd,client_request,1);
        }else if(ready_events[i].events&EPOLLIN){ //et模式下不会重复触发
            while(1){
                //有事件发生
                if ((ready_events[i].events & EPOLLERR) || (ready_events[i].events & EPOLLHUP)
                    || (!(ready_events[i].events & EPOLLIN))) {
                    close(fd);
                    continue;
                }
                // put task into thread pool
                pool_add_worker(parse_http_request,ready_events[i].data.ptr);
            }
        }
    }
}

