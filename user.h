#ifndef user_h
#define user_h

#include "sql.h"
#include <string.h>

#define SQL_INSERT_USER_BASE	"INSERT INTO Bruker (navn, epost, tlf, adresse, byen, postkode, gender) VALUES ('','','','','','','');"
#define SQL_INSERT_USER_FORMAT	"INSERT INTO Bruker (navn, epost, tlf, adresse, byen, postkode, gender) VALUES ('%s','%s','%s','%s','%s','%s','%c');"

#define SQL_SELECT_USER_ID_BASE      "SELECT bruker_id FROM Bruker WHERE navn=''"
#define SQL_SELECT_USER_ID_FORMAT    "SELECT bruker_id FROM Bruker WHERE navn='%s'"

void add_user(char* navn, char* epost, char* tlf, char* adresse, char* byen, char* postkode, char gender) {
//	if(mysql==NULL) sql_init();
/*	char* buf=malloc(strlen(SQL_INSERT_USER_BASE)+strlen(navn)+strlen(epost)+strlen(tlf)+strlen(adresse)+strlen(byen)+strlen(postkode)+1+1);
	sprintf(buf, SQL_INSERT_USER_FORMAT, navn, epost, tlf, adresse, byen, postkode, gender);
	sql_query(buf);*/

	sql_queryf(strlen(SQL_INSERT_USER_BASE)+strlen(navn)+strlen(epost)+strlen(tlf)+strlen(adresse)+strlen(byen)+strlen(postkode)+1+1, SQL_INSERT_USER_FORMAT, navn, epost, tlf, adresse, byen, postkode, gender);
	free(buf);
}
char* getUid(char* navn) {
/*        char* buf=malloc(strlen(SQL_SELECT_USER_ID_BASE)+strlen(navn)+1);
        sprintf(buf, SQL_SELECT_USER_ID_FORMAT, navn);
        SQL_RES* res=sql_query(buf);*/

	sql_queryf(strlen(SQL_SELECT_USER_ID_BASE)+strlen(navn)+1, SQL_SELECT_USER_ID_FORMAT, navn);
        SQL_ROW row=sql_fetch_row(res);
        char* buf2=row[0];
        sql_free_result(res);
        return strdup(buf2);
}

#endif
