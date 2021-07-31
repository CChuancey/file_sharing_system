#include "utils.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "cJSON.h"
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include "http_conn.h"
#include <errno.h>

#define exitErr(func) {perror(func);exit(EXIT_FAILURE);}
#define PATH_LEN 300

int connect_to_sql(MYSQL** mysql){
    *mysql = mysql_init(NULL);
    assert(*mysql!=NULL);
    unsigned int timeout = 3000;
    mysql_options(*mysql,MYSQL_OPT_CONNECT_TIMEOUT,&timeout);
    if(mysql_real_connect(*mysql,DBHOST,DBUSER,DBPASSWD,DBNAME,DBPORT,NULL,0)==NULL){
        fprintf(stderr,"Failed to connect to database: Error: %s\n",mysql_error(*mysql));
        return -1;
    }
    return 0;
}

char* get_user_info(char* username){
    char sql_str[SQL_STR_LEN]; 
    sprintf(sql_str,"SELECT * FROM user WHERE name='%s';",username);
    MYSQL* mysql=NULL;
    if(connect_to_sql(&mysql)==-1) return NULL;//得到空查询
    if(mysql==NULL) {
        fprintf(stderr,"connect_to_sql failed\n");
        return NULL;
    }
    if(mysql_real_query(mysql,sql_str,strlen(sql_str))!=0){
        fprintf(stderr,"mysql query failed:%s\n",mysql_error(mysql));
        return NULL;
    }
    MYSQL_RES* res = mysql_store_result(mysql);
    if(res==NULL){
        fprintf(stderr,"fetch result failed: %s\n",mysql_error(mysql));
        return NULL;
    }
    MYSQL_ROW row=mysql_fetch_row(res);
    if(row==NULL){
        fprintf(stderr,"mysql_fetch_row errr\n");
        return NULL;
    }
    char* ret = (char*)malloc(sizeof(char)*SQL_STR_LEN);//限制结果集为1024
    sprintf(ret,"total=%s&used=%s",row[3],row[4]);

    mysql_free_result(res);
    mysql_close(mysql);
    mysql_library_end();
    return ret; //记得释放！！
}

char* get_json_str(const char* url){
    DIR* dir = opendir(url);
    if(dir==NULL) return NULL;
    struct dirent* item=NULL;
    struct stat stat_buf;
    //先创建一个对象
    cJSON* res = cJSON_CreateObject();
    if(res==NULL) return NULL;

    cJSON* file_arry = cJSON_CreateArray();
    if(file_arry==NULL) return NULL;
    cJSON_AddItemToObject(res,"list",file_arry);

    cJSON* name=NULL;
    cJSON* type=NULL;
    cJSON* size=NULL;
    cJSON* m_time=NULL;

    while((item=readdir(dir))!=NULL){
        char filePath[PATH_LEN*2];
        sprintf(filePath,"%s/%s",url,item->d_name);
        if(stat(filePath,&stat_buf)==-1) exitErr("stat()");
        if(strcasecmp(".",item->d_name)==0||strcasecmp("..",item->d_name)==0){
            continue;
        }
        cJSON* cur = cJSON_CreateObject();
        if(cur==NULL) return NULL;
        cJSON_AddItemToArray(file_arry,cur);

        name = cJSON_CreateString(item->d_name);
        cJSON_AddItemToObject(cur,"name",name);

        //dir?
        if(S_ISDIR(stat_buf.st_mode)) {
            type = cJSON_CreateString("dir");
        }else{
            type = cJSON_CreateString("reg");
        }
        cJSON_AddItemToObject(cur,"type",type);

        //size
        size = cJSON_CreateNumber(stat_buf.st_size);
        cJSON_AddItemToObject(cur,"size",size);

        //time
        char* ac_time = ctime(&stat_buf.st_ctime)+4;
        ac_time[strlen(ac_time)-1]='\0';
        m_time = cJSON_CreateString(ac_time);
        cJSON_AddItemToObject(cur,"time",m_time);
    }

    char* ret = cJSON_Print(res);
    cJSON_Delete(res);
    return ret;
}

int getline_from_socket(int sockfd,char* buf,int remain){
    int i=0;
    char c='\0';
    while(i<remain&&c!='\n'){
        int n=recv(sockfd,&c,1,0);
        if(n>0){
            if(c=='\r'){//将请求头的\r\n替换为\n读进缓冲区
                n=recv(sockfd,&c,1,MSG_PEEK); //确保为\r\n PEEK保证只读不取
                if(n>0&&c=='\n')
                    recv(sockfd,&c,1,0);
                else
                    c='\n';
            }
            buf[i++]=c;
        }else {//包括读错
            c='\n';
        }
    }
    if(i==remain) return -1;//一行过长，请求错误
    buf[i]='\0';
    return i;
}
//需要自己释放空间                                                                  
char* get_formated_time_str(){
    time_t t = time(NULL);
    struct tm* buf = localtime(&t);
    char* res = (char*)malloc(sizeof(char)*20);
    sprintf(res,"%d-%d-%d %d:%d:%d",buf->tm_year+1900,buf->tm_mon+1,buf->tm_mday,
            buf->tm_hour+1,buf->tm_min,buf->tm_sec);
    return res;
}

int share_process(char* username,char* parms){
    //先处理参数
    char* bk = (char*)malloc(strlen(parms));
    memcpy(bk,parms,strlen(parms));
    size_t len = strspn(bk,"url=");
    char* url = bk+len;
    char* cmd = strpbrk(url,"&");
    *cmd++='\0';
    cmd+=4;
    char* end = strpbrk(cmd,"\r\n");
    *end++='\0';
    char sql_str[SQL_STR_LEN]; 

    MYSQL* mysql=NULL;
    if(connect_to_sql(&mysql)==-1) return -1;//得到空查询
    if(mysql==NULL) {
        fprintf(stderr,"connect_to_sql failed\n");
        return -1;
    }
    char prepath[PATH_LEN];
    char newpath[PATH_LEN];

    //先尝试建立各个用户的共享文件夹,暂时只支持各个用户根目录共享文件
    sprintf(prepath,"../doc/%s",username);
    sprintf(newpath,"../doc/shared_folder/%s",username);
    int ret = mkdir(prepath,0600);
    if(ret==-1&&errno!=EEXIST){
        perror("mkdir");
        return -1;
    }
    ret = mkdir(newpath,0600);
    if(ret==-1&&errno!=EEXIST){
        perror("mkdir");
        return -1;
    }

    sprintf(prepath,"../doc/%s%s",username,url);
    sprintf(newpath,"../doc/shared_folder/%s%s",username,url);

    if(strncasecmp(cmd,"add",3)==0){//增加共享
        char* cur_time = get_formated_time_str();
        sprintf(sql_str,"INSERT INTO shared VALUES('%s','%s','%s');",username,url,cur_time);
        free(cur_time);//keep in mind
        if(mysql_real_query(mysql,sql_str,strlen(sql_str))!=0){
            fprintf(stderr,"mysql query failed:%s\n",mysql_error(mysql));
            return -1;
        }
        if(mysql_affected_rows(mysql)>0){
            puts("insert sql ok!");
        }else {
            fprintf(stderr,"mysql insert rows failed:%s\n",mysql_error(mysql));
            return -1;
        }
        if(link(prepath,newpath)==-1) {
            perror("link()");
            return -1;
        }
    }else if(strncasecmp(cmd,"del",3)==0){//取消共享
        sprintf(sql_str,"DELETE FROM shared WHERE url='%s' AND username = '%s';",url,username);
        if(mysql_real_query(mysql,sql_str,strlen(sql_str))!=0){
            fprintf(stderr,"mysql query failed:%s\n",mysql_error(mysql));
            return -1;
        }
        if(mysql_affected_rows(mysql)>0){
            puts("delete segment ok!");
        }else {
            fprintf(stderr,"mysql del rows failed:%s\n",mysql_error(mysql));
            return -1;
        }
        if(unlink(newpath)==-1) {
            perror("unlink()");
            return -1;
        }
    }

    free(bk);
    return 0;
}

