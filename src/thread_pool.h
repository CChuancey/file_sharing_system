#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>

//任务链表
typedef struct Worker{
    void* (*process)(void* arg);
    void* arg;
    struct Worker* next;
}CThread_worker;

//线程池结构
typedef struct{
    pthread_mutex_t queue_lock;
    pthread_cond_t queue_ready;//条件变量
    CThread_worker* queue_head;
    int shutdown;
    pthread_t* threadid;
    int max_thread_num;
    int cur_queue_size;
}CThread_pool;

void pool_init(int);//初始化线程池
int pool_add_worker(void* (*process)(void* arg),void*);
int pool_destory(); //销毁线程池
void* thread_routine(void*);//工作线程
void* func(void*);//测试任务

extern CThread_pool* thread_pool;

 
#endif
