#ifndef revision_h
#define revision_h

#include "sql.h"
#include <string.h>

#define SQL_INSERT_REVISION_BASE	"INSERT INTO Endring (fil_id, hash, dato, generasjon) VALUES ('','',,'');"
#define SQL_INSERT_REVISION_FORMAT	"INSERT INTO Endring (fil_id, hash, dato, generasjon) VALUES ('%s','%s',%s,'%d');"

#define SQL_SELECT_REVISION_BASE	"SELECT * FROM Endring WHERE fil_id=''"
#define SQL_SELECT_REVISION_FORMAT        "SELECT * FROM Endring WHERE fil_id='%s'"

void add_revision(char* fil_id, char* hash, char* dato, int generasjon) {
	sql_queryf(strlen(SQL_INSERT_REVISION_BASE)+strlen(fil_id)+strlen(hash)+strlen(dato)+8+1, SQL_INSERT_REVISION_FORMAT, fil_id,hash,dato,generasjon);
//	free(buf);
}
void add_current_revision(char* fil_id, char* hash) {
	add_revision(fil_id,hash,"NOW()",count_fileRevisions(fil_id));
}

int count_fileRevisions(char* filId) {
        sql_queryf(strlen(SQL_SELECT_REVISION_BASE)+strlen(filId), SQL_SELECT_REVISION_FORMAT, filId);
	return mysql_num_rows(res);
}
void list_fileRevisions(char* filId) {
	sql_queryf(strlen(SQL_SELECT_REVISION_BASE)+strlen(filId), SQL_SELECT_REVISION_FORMAT, filId);
}
#endif
