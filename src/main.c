#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>
#include <assert.h>
#include "epoll.h"
#include "thread_pool.h"
#include "http_conn.h"

#define exitErr(func) {perror(func);exit(EXIT_FAILURE);}
#define LOCK_FILE_PATH "webserver.pid"
#define EVENTS_MAX_NUM 500

int exit_flag = 0;
int thread_num = 0;
int listenfd = -1;

int epfd=-1;
int clientnum=0;

void show_help_msg(){
    printf("this is help msg!\n");
}

void init_arguments(int* argc,char*** argv){
    int opt;
    while((opt=getopt(*argc,*argv,"bhkt:"))!=-1){
        switch(opt){
        case 'b'://后台运行
            if(daemon(0,0)==-1) exitErr("daemon()");
            break;
        case 'h'://显示帮助文档
            show_help_msg();
            break;
        case 'k'://杀死守护进程
            exit_flag = 1;
            break;
        case 't':
            //线程数
            thread_num = atoi(optarg);
            printf("the thread pool is using %d threads to handle events!\n",thread_num);
            break;
        default:
            fprintf(stderr,"Invalid input,\nPlease type -h to get help message.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void add_lock(int lock_fd,int type,off_t offset,int whence,off_t len){
    struct flock lock;
    lock.l_len = len;
    lock.l_start = offset;
    lock.l_type = type;
    lock.l_whence = whence;
    if(fcntl(lock_fd,F_SETLKW,&lock)==-1) exitErr("setlkw fcntl()");
}

pid_t lock_test(int lock_fd,int type,off_t offset,int whence,off_t len){
    struct flock lock;
    lock.l_len = len;
    lock.l_start = offset;
    lock.l_type = type;
    lock.l_whence = whence;

    if(fcntl(lock_fd,F_GETLK,&lock)==-1) exitErr("fcntl()");
    if(lock.l_type == F_UNLCK) return 0; //未被加锁
    return lock.l_pid;
}

void kill_webserver(pid_t pid){
    if(kill(pid,SIGKILL)==-1) exitErr("kill()");

    // 释放已经申请的内存
    // extern .....
    //free(....);
}

int main(int argc,char** argv) {
    mode_t premask = umask(0);
    int lock_fd = open(LOCK_FILE_PATH,O_CREAT | O_RDWR ,0600);
    umask(premask);
    if(lock_fd==-1) exitErr("lock_fd open()");

    init_arguments(&argc,&argv);
    //检测当前是否已经运行了一个进程
    pid_t pid =  lock_test(lock_fd,F_RDLCK,0,SEEK_SET,0);
    if(exit_flag){ //直接退出进程
        if(pid > 0) {
            kill_webserver(pid);
            exit(EXIT_SUCCESS);
        } else exit(EXIT_SUCCESS);       
    }else{
        if(pid>0) {
            fprintf(stderr,"webServer is already running!\n");
            exit(EXIT_FAILURE);
        }
        add_lock(lock_fd,F_WRLCK,0,SEEK_SET,0);
    }


    openlog("webServer",LOG_NDELAY|LOG_PID,LOG_DAEMON);
    syslog(LOG_INFO,"webServer started successfully!\n");

    listenfd = init_server_socket(12346,500);
    //connfd 要设置成非阻塞的,并放进监听池中
    epfd = epoll_create(1);
    assert(epfd!=-1);

    http_request_t* request = (http_request_t* )malloc(sizeof(http_request_t));
    init_http_request(listenfd,epfd,request);
    addfd(epfd,request,0);

    struct epoll_event ready_events[EVENTS_MAX_NUM];

    pool_init(8); //初始化线程池
    puts("thread pool created!");
    while(1) {
        int nums = epoll_wait(epfd,ready_events,EVENTS_MAX_NUM,-1);
        assert(nums!=-1);
        et(epfd,listenfd,nums,ready_events); //发现请求后放进线程池
    }
    pool_destory();
    closelog();
    close(listenfd);
    return 0;
}

