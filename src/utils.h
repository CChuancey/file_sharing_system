#ifndef __UTILS_H__
#define __UTILS_H__

#define DBHOST "127.0.0.1"
#define DBPORT 3306
#define DBUSER "chuancey"
#define DBPASSWD "Zhangsan@elem123"
#define DBNAME "file_sharing_system"
#define SQL_STR_LEN 1024

#include <mysql/mysql.h>
#include "http_conn.h"

char* get_user_info(char*);

#endif