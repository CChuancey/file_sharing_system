#include <stdio.h>
#include <mysql/mysql.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define DBHOST "127.0.0.1"
#define DBPORT 3306
#define DBUSER "chuancey"
#define DBPASSWD "Zhangsan@elem123"
#define DBNAME "file_sharing_system"

#define SQL_STR_LEN 1024

int main(int argc,char** argv){
    if(argc!=3) {
        fprintf(stderr,"Please use correct parameters.\n");
        exit(EXIT_FAILURE);
    }
    char* username = argv[1];
    char* passwd = argv[2];
    MYSQL* mysql = mysql_init(NULL);
    unsigned int timeout = 3000;
    mysql_options(mysql,MYSQL_OPT_CONNECT_TIMEOUT,&timeout);
    if(mysql_real_connect(mysql,DBHOST,DBUSER,DBPASSWD,DBNAME,DBPORT,NULL,0)==NULL){
        fprintf(stderr,"Failed to connect to database: Error: %s\n",mysql_error(mysql));
        exit(EXIT_FAILURE);
    }
    puts("mysql connect successfully!");

    char sqlstr[SQL_STR_LEN];
    sprintf(sqlstr,"SELECT * FROM user WHERE name='%s' and password = '%s';",username,passwd);
    
    if(mysql_real_query(mysql,sqlstr,strlen(sqlstr))!=0){
        fprintf(stderr,"sql query failed:%s\n",mysql_error(mysql));
        exit(EXIT_FAILURE);
    }
    MYSQL_RES* res = mysql_store_result(mysql);
    if(res==NULL){
        fprintf(stderr,"sql fetch result failed:%s\n",mysql_error(mysql));
        exit(EXIT_FAILURE);
    }
    unsigned int res_num = mysql_num_rows(res);
    mysql_free_result(res);
    mysql_close(mysql);
    mysql_library_end();

    printf("res num:%d\n",res_num);
    if(res_num==1) {
        puts("user exists");
        exit(EXIT_SUCCESS);
    }else exit(EXIT_FAILURE);
}

