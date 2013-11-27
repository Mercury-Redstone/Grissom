#include <stdio.h>
#include "sql.h"
#include "file.h"

#define SQL_SELECT_REVISION_HASH_BASE	"SELECT hash FROM Endring WHERE fil_id='' ORDER BY generasjon DESC"
#define SQL_SELECT_REVISION_HASH_FORMAT	"SELECT hash FROM Endring WHERE fil_id='%s' ORDER BY generasjon DESC"

char* hash(char* fileName) {
	char* cmd=malloc(strlen("sha512sum ")+strlen(fileName));
	sprintf(cmd, "sha512sum %s", fileName);
	FILE* file=popen(cmd, "r");
	char* ret=malloc(128);
	fscanf(file, "%128s", ret);
	pclose(file);
//	printf(ret);
	return ret;
}

char* prevHashFor(char* fileName) {
	char* buf=malloc(strlen(SQL_SELECT_REVISION_HASH_BASE));
	char* fileId=getFileId(fileName);
	if(strcmp(fileId,"")) {
		sprintf(buf,SQL_SELECT_REVISION_HASH_FORMAT, fileId);
		SQL_RES* res=sql_query(buf);
		free(buf);
		if(sql_num_rows(res)!=0)
			buf=sql_fetch_row(res)[0];
		sql_free_result(res);
	}
	return "";
}

int fileChanged(char* fileName) {
	return strcmp(prevHashFor(fileName), hash(fileName))!=0;
}
