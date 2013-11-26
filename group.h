#ifndef gruppe_h
#define gruppe_h

#include "sql.h"

char* getGid(char*);

#include "membership.h"

#include <string.h>

#define SQL_INSERT_GROUP_BASE	"INSERT INTO Gruppe (gruppe_Navn) VALUES ('');"
#define SQL_INSERT_GROUP_FORMAT	"INSERT INTO Gruppe (gruppe_Navn) VALUES ('%s');"

#define SQL_SELECT_GROUP_ID_BASE      "SELECT gruppe_id FROM Gruppe WHERE gruppe_Navn=''"
#define SQL_SELECT_GROUP_ID_FORMAT    "SELECT gruppe_id FROM Gruppe WHERE gruppe_Navn='%s'"

void add_group(char* navn) {
//	if(mysql==NULL) sql_init();
	char* buf=malloc(strlen(SQL_INSERT_GROUP_BASE)+strlen(navn)+1);
	sprintf(buf, SQL_INSERT_GROUP_FORMAT, navn);
	sql_query(buf);
	free(buf);
}

char* getGid(char* navn) {
	char* buf=malloc(strlen(SQL_SELECT_GROUP_ID_BASE)+strlen(navn)+1);
        sprintf(buf, SQL_SELECT_GROUP_ID_FORMAT, navn);
        SQL_RES* res=sql_query(buf);
        SQL_ROW row=sql_fetch_row(res);
        char* buf2=row[0];
        sql_free_result(res);
        return buf2;
}
#endif
