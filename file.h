#ifndef file_h
#define file_h

#include "sql.h"
#include "catalog.h"
#include <string.h>

#define SQL_INSERT_FILE_BASE	"INSERT INTO Fil (filNavn, bruker_id, gruppe_id, katalog_id, eier, skal_overvake) VALUES ('','','','','','');"
#define SQL_INSERT_FILE_FORMAT	"INSERT INTO Fil (filNavn, bruker_id, gruppe_id, katalog_id, eier, skal_overvake) VALUES ('%s','%s','%s','%s','%s','%d');"

#define SQL_SELECT_FILE_ID_BASE "SELECT fil_id FROM Fil WHERE filNavn='' AND katalog_id=''"
#define SQL_SELECT_FILE_ID_FORMAT "SELECT fil_id FROM Fil WHERE filNavn='%s' AND katalog_id='%s'"

#define SQL_SELECT_FILE_ID_CHECKABLE   "SELECT fil_id FROM Fil WHERE skal_overvake='1'"
void add_file(char* navn, char* bruker, char* gruppe, char* katalog, char* eier, int skal_overvake) {
//	if(mysql==NULL) sql_init();
	char* buf=malloc(strlen(SQL_INSERT_FILE_BASE)+strlen(navn)+4*5*sizeof(int));
	sprintf(buf, SQL_INSERT_FILE_FORMAT, navn, bruker, gruppe, katalog, eier, skal_overvake);
	sql_query(buf);
	free(buf);
}

char* getFileId(char* navn) {
	int indexOfLastSlash=((int)strrchr(navn,'/'))-(int)navn;
	char* filNavn=(char*)(navn+indexOfLastSlash+1);
	char* katalog=malloc(indexOfLastSlash);
	strncpy(katalog, navn, indexOfLastSlash);
	katalog[indexOfLastSlash]='\0';

//	printf("%s : %s\n", katalog, filNavn);

	char* katalogId=getCatalogId(katalog);
	char* buf=malloc(strlen(SQL_SELECT_FILE_ID_BASE)+strlen(filNavn)+strlen(katalogId));
	sprintf(buf, SQL_SELECT_FILE_ID_FORMAT, filNavn, katalogId);
	SQL_RES* res=sql_query(buf);
	char* ret;
	int rows=sql_num_rows(res);
	if(rows==1) {ret=sql_fetch_row(res)[0];sql_free_result(res);}
	else ret="";
	return ret;
}

char** checkableFiles() {
	SQL_RES* res=sql_query(SQL_SELECT_FILE_ID_CHECKABLE);
	char** ret=(char**)malloc((sql_num_rows(res)+1)*sizeof(char*));
	int i=0;
	char** row=sql_fetch_row(res);
	while(i<sql_num_rows(res)) {
		ret[i]=strdup(row[i]);
		i++;
	}
	ret[i]=NULL;
	sql_free_result(res);
	return ret;
}
#endif
