#ifndef sql_h
#define sql_h 1

#define SQL_HOST "localhost"
#define SQL_DB   "johdah"
#define SQL_USER "johdah"
#define SQL_PASS "1234"

#include <mysql/mysql.h> // Ref: http://dev.mysql.com/doc/refman/5.0/en/c-api.html
#include <mysql/my_global.h>
#include <mysql/my_sys.h>

void sql_init() {
	my_init();
}

#endif
