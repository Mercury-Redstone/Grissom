#ifndef catalog_h
#define catalog_h

#include "sql.h"
#include <string.h>

#define SQL_INSERT_CATALOG_BASE		"INSERT INTO Katalog (navn) VALUES ('');"
#define SQL_INSERT_CATALOG_FORMAT	"INSERT INTO Katalog (navn) VALUES ('%s');"

#define SQL_SELECT_CATALOG_ID_BASE	"SELECT katalog_id FROM Katalog WHERE navn=''"
#define SQL_SELECT_CATALOG_ID_FORMAT	"SELECT katalog_id FROM Katalog WHERE navn='%s'"

#define SQL_SELECT_CATALOG_NAME_BASE      "SELECT navn FROM Katalog WHERE katalog_id=''"
#define SQL_SELECT_CATALOG_NAME_FORMAT    "SELECT navn FROM Katalog WHERE katalog_id='%s'"
void add_catalog(char* navn) {
	sql_queryf(strlen(SQL_INSERT_CATALOG_BASE)+strlen(navn)+1, SQL_INSERT_CATALOG_FORMAT, navn);
	free(buf);
}
char* getCatalogId(char* navn) {
	sql_queryf(strlen(SQL_SELECT_CATALOG_ID_BASE)+strlen(navn)+1, SQL_SELECT_CATALOG_ID_FORMAT, navn);
	SQL_ROW row=sql_fetch_row(res);

	char* buf2=row[0];
	sql_free_result(res);
	return strdup(buf2);
}
char* getCatalogName(char* id) {
	sql_queryf(strlen(SQL_SELECT_CATALOG_NAME_BASE)+strlen(id)+1,  SQL_SELECT_CATALOG_NAME_FORMAT, id);
        SQL_ROW row=sql_fetch_row(res);
        char* buf2=row[0];
        sql_free_result(res);
        return strdup(buf2);
}

#endif
