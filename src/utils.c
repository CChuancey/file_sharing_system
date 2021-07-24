#include "utils.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
