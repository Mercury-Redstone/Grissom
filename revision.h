#ifndef revision_h
#define revision_h

#include "sql.h"
#include <string.h>

#define SQL_INSERT_REVISION_BASE	"INSERT INTO Endring (fil_id, hash, dato, generasjon) VALUES ('','','','');"
#define SQL_INSERT_REVISION_FORMAT	"INSERT INTO Endring (fil_id, hash, dato, generasjon) VALUES ('%s','%s','%s','%d');"

void add_revision(char* fil, char* hash, char* dato, int generasjon) {
	sql_queryf(strlen(SQL_INSERT_REVISION_BASE)+strlen(fil)+strlen(hash)+strlen(dato)+8+1, SQL_INSERT_REVISION_FORMAT, fil,hash,dato,generasjon);
	free(buf);
}

#endif
