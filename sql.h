#ifndef sql_h
#define sql_h

#define SQL_HOST "localhost"
#define SQL_DB   "johdah"
#define SQL_USER "johdah"
#define SQL_PASS "1234"

#include <mysql/mysql.h> // Ref: http://dev.mysql.com/doc/refman/5.0/en/c-api.html
#include <mysql/my_global.h>
#include <mysql/my_sys.h>

MYSQL* mysql=NULL;

void sql_failOnError() {
        if(mysql_errno(mysql)!=0)
        {
                fprintf(stderr, "%s\n\n", mysql_error(mysql));
		assert(1==2);
                exit(1);
        }
}

void sql_init() {
	assert(mysql==NULL);
	mysql=mysql_init(NULL);
	sql_failOnError();
	assert(mysql!=NULL);

	mysql=mysql_real_connect(mysql, SQL_HOST, SQL_USER, SQL_PASS, SQL_DB, 0, NULL, 0);
        sql_failOnError();
	assert(mysql!=NULL);
}
MYSQL_RES* sql_query(const char* query) {
	printf("SQL: %s\n", query);
	if(mysql==NULL) sql_init();
	mysql_query(mysql,query);
        sql_failOnError();
	MYSQL_RES* result = mysql_store_result(mysql);
        sql_failOnError();
	return result;
}
void sql_free_result(MYSQL_RES* result) {
	if(result==NULL)return;
	mysql_free_result(result);
}

#endif
