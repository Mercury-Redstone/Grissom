#ifndef sql_h
#define sql_h 1

#define SQL_HOST "localhost"
#define SQL_DB   "johdah"
#define SQL_USER "johdah"
#define SQL_PASS "1234"

#include <mysql/mysql.h> // Ref: http://dev.mysql.com/doc/refman/5.0/en/c-api.html
#include <mysql/my_global.h>
#include <mysql/my_sys.h>

MYSQL* mysql=NULL;

void sql_init() {
	assert(mysql==NULL);
	mysql=mysql_init(NULL);
	assert(mysql!=NULL);

	mysql=mysql_real_connect(mysql, SQL_HOST, SQL_USER, SQL_PASS, SQL_DB, 0, NULL, 0);
	assert(mysql!=NULL);
}
MYSQL_RES* sql_query(const char* query) {
	assert(mysql_query(mysql,query)==0);
	MYSQL_RES* result = mysql_store_result(mysql);
	return result;
}
void sql_free_result(MYSQL_RES* result) {
	assert(result!=NULL);
	mysql_free_result(result);
}


#endif
