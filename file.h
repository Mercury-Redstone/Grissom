#ifndef file_h
#define file_h

#include "sql.h"
#include <string.h>

#define SQL_INSERT_FILE_BASE	"INSERT INTO Fil (filNavn, bruker_id, gruppe_id, katalog_id, eier, skal_overvake) VALUES ('','','','','','');"
#define SQL_INSERT_FILE_FORMAT	"INSERT INTO Fil (filNavn, bruker_id, gruppe_id, katalog_id, eier, skal_overvake) VALUES ('%s','%d',%d,'%d','%d','%d');"

void add_file(char* navn, int bruker, int gruppe, int katalog, int eier, int skal_overvake) {
	if(mysql==NULL) sql_init();
	char* buf=malloc(strlen(SQL_INSERT_FILE_BASE)+strlen(navn)+4*5*sizeof(int));
	sprintf(buf, SQL_INSERT_FILE_FORMAT, navn, bruker, gruppe, katalog, eier, skal_overvake);
	sql_query(buf);
	free(buf);
}

#endif
