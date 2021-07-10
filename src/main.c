#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#define exitErr(func) {perror(func);exit(EXIT_FAILURE);}
#define LOCK_FILE_PATH "webserver.pid"

int exit_flag = 0;
int thread_num = 0;

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
        add_lock(lock_fd,F_WRLCK,0,SEEK_SET,0);
    }

    while(1) pause();
    return 0;
}

