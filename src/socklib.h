#ifndef __SOCKLIB_H__
#define __SOCKLIB_H__
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define exitErr(func) {perror(func);exit(EXIT_FAILURE);}

int init_server_socket(int portnum,int backlog);
#endif
