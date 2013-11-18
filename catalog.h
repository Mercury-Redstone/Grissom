#ifndef catalog_h
#define catalog_h

#include "sql.h"
#include <string.h>

#define SQL_INSERT_CATALOG_BASE		"INSERT INTO Katalog (navn) VALUES ('');"
#define SQL_INSERT_CATALOG_FORMAT	"INSERT INTO Katalog (navn) VALUES ('%s');"

void add_catalog(char* navn) {
	if(mysql==NULL) sql_init();
	char* buf=malloc(strlen(SQL_INSERT_CATALOG_BASE)+strlen(navn)+1);
	sprintf(buf, SQL_INSERT_CATALOG_FORMAT, navn);
	sql_query(buf);
	free(buf);
}

#endif
