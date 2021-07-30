#ifndef __UTILS_H__
#define __UTILS_H__

//数据库的信息
#define DBHOST "127.0.0.1"
#define DBPORT 3306
#define DBUSER "chuancey"
#define DBPASSWD "Zhangsan@elem123"
#define DBNAME "file_sharing_system"
#define SQL_STR_LEN 1024

#include <mysql/mysql.h>
#include "http_conn.h"

char* get_user_info(char*);
char* get_json_str(const char* url);
int getline_from_socket(int,char*,int);
#endif
