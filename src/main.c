#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define exitErr(func) {perror(func);exit(EXIT_FAILURE);}
#define LOCK_FILE_PATH "/var/run/webserver.pid"

int main()
{
    mode_t premask = umask(0);
    int lock_fd = open(LOCK_FILE_PATH,O_CREAT | O_RDWR ,0600);
    umask(premask);
    if(lock_fd==-1) exitErr("lock_fd open()");

    return 0;
}

