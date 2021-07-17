#ifndef __EPOLL_H__
#define __EPOLL_H__ 
#include <stdio.h>
#include <stdlib.h>
#include "socklib.h"
#include <assert.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "http_conn.h"

#define max(a,b) a>b?a:b;
#define exitErr(func) {perror(func);exit(EXIT_FAILURE);}

#define BUFFSIZE 1024
#define MAXEVENTS 1024

int setnonblocking(int);
void addfd(int epollfd,http_request_t*,int enable_et);
void removefd(int epollfd,http_request_t*);
void modfd(int epollfd,http_request_t*,int);
void et(int epfd,int listenfd,int nums,struct epoll_event ready_events[]);
 
extern int epfd;
extern int clientnum;

#endif
