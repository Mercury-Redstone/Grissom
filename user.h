#ifndef user_h
#define user_h

#include "sql.h"
#include <string.h>

#define SQL_INSERT_USER_BASE	"INSERT INTO Bruker (navn, epost, tlf, adresse, byen, postkode, gender) VALUES ('','','','','','','');"
#define SQL_INSERT_USER_FORMAT	"INSERT INTO Bruker (navn, epost, tlf, adresse, byen, postkode, gender) VALUES ('%s','%s','%s','%s','%s','%s','%c');"

void add_user(char* navn, char* epost, char* tlf, char* adresse, char* byen, char* postkode, char gender) {
	if(mysql==NULL) sql_init();
	char* buf=malloc(strlen(SQL_INSERT_USER_BASE)+strlen(navn)+strlen(epost)+strlen(tlf)+strlen(adresse)+strlen(byen)+strlen(postkode)+1+1);
	sprintf(buf, SQL_INSERT_USER_FORMAT, navn, epost, tlf, adresse, byen, postkode, gender);
	sql_query(buf);
	free(buf);
}

#endif
