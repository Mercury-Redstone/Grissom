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
	sql_queryf(strlen(SQL_INSERT_GROUP_BASE)+strlen(navn)+1, SQL_INSERT_GROUP_FORMAT, navn);
	free(buf);
}

char* getGid(char* navn) {
	sql_queryf(strlen(SQL_SELECT_GROUP_ID_BASE)+strlen(navn)+1, SQL_SELECT_GROUP_ID_FORMAT, navn);
        SQL_ROW row=sql_fetch_row(res);
        char* buf2=row[0];
        sql_free_result(res);
        return strdup(buf2);
}
#endif
