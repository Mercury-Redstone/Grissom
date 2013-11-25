#ifndef catalog_h
#define catalog_h

#include "sql.h"
#include <string.h>

#define SQL_INSERT_CATALOG_BASE		"INSERT INTO Katalog (navn) VALUES ('');"
#define SQL_INSERT_CATALOG_FORMAT	"INSERT INTO Katalog (navn) VALUES ('%s');"

#define SQL_SELECT_CATALOG_ID_BASE	"SELECT katalog_id FROM Katalog WHERE navn=''"
#define SQL_SELECT_CATALOG_ID_FORMAT	"SELECT katalog_id FROM Katalog WHERE navn='%s'"
void add_catalog(char* navn) {
	if(mysql==NULL) sql_init();
	char* buf=malloc(strlen(SQL_INSERT_CATALOG_BASE)+strlen(navn)+1);
	sprintf(buf, SQL_INSERT_CATALOG_FORMAT, navn);
	sql_query(buf);
	free(buf);
}
char* getCatalogId(char* navn) {
	char* buf=malloc(strlen(SQL_SELECT_CATALOG_ID_BASE)+strlen(navn)+1);
        sprintf(buf, SQL_SELECT_CATALOG_ID_FORMAT, navn);
        SQL_RES* res=sql_query(buf);
	SQL_ROW row=sql_fetch_row(res);
	char* buf2=row[0];
	sql_free_result(res);
	return buf2;
}

#endif
