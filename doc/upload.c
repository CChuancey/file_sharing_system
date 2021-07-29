#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

#define FILE_NAME_LEN 100
#define PATH_NAME_LEN 500
#define BUFF_SIZE   1024

#define exitErr(func) {perror(func);exit(EXIT_FAILURE);}

int client_fd=0;
char* filename = NULL;
char* path=NULL;
char* username=NULL;

int main(int argc,char** argv){
    if(argc!=4){
        fprintf(stderr,"upload request parameters error!\nYour argc is %d\n",argc);
        exit(EXIT_FAILURE);
    }
    char* params = (char*)malloc(sizeof(char)*(PATH_NAME_LEN+FILE_NAME_LEN));
    memset(params,'\0',sizeof(params));
    memcpy(params,argv[1],strlen(argv[1]));
    client_fd = atoi(argv[2]);
    size_t len = strspn(params,"filename=");
    filename = params+len;
    char* p = strpbrk(params,"&");
    *p++='\0';
    len = strspn(p,"path=");
    path = p+len;
    char* end = strpbrk(path,"\r\n");
    *end++='\0';

    username = argv[3];

    char url[PATH_NAME_LEN+FILE_NAME_LEN];
    sprintf(url,"../doc/%s%s%s",username,path,filename);

    puts(url);
    mode_t premode =umask(0);
    int nfd = open(url,O_CREAT|O_TRUNC|O_WRONLY,0600);
    umask(premode);
    if(nfd==-1){
        exitErr("open");
    }

    char buf[BUFF_SIZE];
    int count=0;
    while(1){
        ssize_t len = recv(client_fd,buf,BUFF_SIZE,0);
        if(len==-1){
            if(errno==EAGAIN){
                break;
            }
            exitErr("recv");
        }else if(len==0) break;
        int whence=0;
        while(1){
            ssize_t ret = write(nfd,buf+whence,len-whence);
            if(ret==-1){
                if(errno==EAGAIN) break;
                exitErr("write()");
            }else if(ret==0) break;
            whence+=ret;
        }
        count+=len;
    }
    printf("total write:%d\n",count);
    close(nfd);
    free(params);
    return 0;
}
