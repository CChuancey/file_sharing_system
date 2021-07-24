#include "epoll.h"
#include "thread_pool.h"
#include "http_conn.h"

int setnonblocking(int fd){ //设置为非阻塞的fd
    int preStatusFlags = fcntl(fd,F_GETFL);
    int newStatusFlags = preStatusFlags | O_NONBLOCK;
    fcntl(fd,F_SETFL,newStatusFlags);
    return preStatusFlags;
}

void addfd(int epollfd,http_request_t* request,int enable_oneshot){
    struct epoll_event event;
    event.events = EPOLLIN|EPOLLHUP|EPOLLET;
    event.data.ptr = (void*)request;
    int fd = request->sock_fd;
    if(enable_oneshot) event.events |= EPOLLONESHOT;
    if(epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event)==-1) exitErr("epoll_ctl()");
    setnonblocking(fd);
    clientnum++;
}

void modfd(int epollfd,http_request_t* request,int ev){
    struct epoll_event event;
    event.events = ev | EPOLLET | EPOLLRDHUP | EPOLLONESHOT;
    event.data.ptr = (void*)request;
    int fd = request->sock_fd;
    epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&event);
}

void removefd(int epollfd,http_request_t* request){
    epoll_ctl(epollfd,EPOLL_CTL_DEL,request->sock_fd,0);
    close(request->sock_fd);
    clientnum--;
}

void et(int epfd,int listenfd,int nums,struct epoll_event ready_events[]){
    for(int i=0;i<nums;i++){
        http_request_t* requst = (http_request_t*)ready_events[i].data.ptr;//为了携带其他数据,弃用fd采用ptr
        int fd = requst->sock_fd;
        if(fd==listenfd){ //有连接请求
            struct sockaddr_in cliendSockAddr;
            socklen_t len = sizeof(cliendSockAddr);
            int clientSockfd = accept(listenfd,(struct sockaddr*)&cliendSockAddr,&len);
            if(clientSockfd==-1){//非阻塞fd使用阻塞调用时的EAGAIN问题
                if(errno==EAGAIN||errno==EINTR){
                    continue;
                }
                exitErr("accept()");
            }
            puts("Communication has been established with the server");
            http_request_t* client_request = (http_request_t*)malloc(sizeof(http_request_t));
            init_http_request(clientSockfd,epfd,client_request,0);
            addfd(epfd,client_request,1);
        }else if(ready_events[i].events&EPOLLIN){ //et模式下不会重复触发
            // put task into thread pool,process用于处理http请求
            if ((ready_events[i].events & EPOLLERR) || (ready_events[i].events & EPOLLHUP) || (ready_events[i].events&EPOLLRDHUP)
                || (!(ready_events[i].events & EPOLLIN))) {
                removefd(epfd,requst);
                close(fd);
                continue;
            }
            pool_add_worker(process,ready_events[i].data.ptr);
        }else if(ready_events[i].events&EPOLLOUT){
            //puts("epollout ready!");
            if(write_sock(requst)==-1) {
                puts("write_sock error || connction is 0");
                close_conn(requst);
            }
        }else{
        }
    }
}

