#ifndef revision_h
#define revision_h

#include "sql.h"
#include <string.h>

#define SQL_INSERT_REVISION_BASE	"INSERT INTO Endring (fil_id, hash, dato, generasjon) VALUES ('','','','');"
#define SQL_INSERT_REVISION_FORMAT	"INSERT INTO Endring (fil_id, hash, dato, generasjon) VALUES ('%s','%s','%s','%d');"

void add_revision(char* fil, char* hash, char* dato, int generasjon) {
//	if(mysql==NULL) sql_init();
	char* buf=malloc(strlen(SQL_INSERT_REVISION_BASE)+strlen(fil)+strlen(hash)+strlen(dato)+8+1);
	sprintf(buf, SQL_INSERT_REVISION_FORMAT, fil,hash,dato,generasjon);
	sql_query(buf);
	free(buf);
}

#endif
