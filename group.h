#ifndef gruppe_h
#define gruppe_h

#include "sql.h"
#include <string.h>

#define SQL_INSERT_GROUP_BASE	"INSERT INTO Gruppe (gruppe_Navn) VALUES ('');"
#define SQL_INSERT_GROUP_FORMAT	"INSERT INTO Gruppe (gruppe_Navn) VALUES ('%s');"

void add_group(char* navn) {
	if(mysql==NULL) sql_init();
	char* buf=malloc(strlen(SQL_INSERT_GROUP_BASE)+strlen(navn)+1);
	sprintf(buf, SQL_INSERT_GROUP_FORMAT, navn);
	sql_query(buf);
	free(buf);
}

#endif
