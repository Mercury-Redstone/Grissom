#include <stdio.h>
#include "sql.h"
#include "file.h"

char* hash(char* fileName) {
	char* cmd=malloc(strlen("sha512sum ")+strlen(fileName));
	sprintf(cmd, "sha512sum %s", fileName);
	FILE* file=popen(cmd, "r");
	char* ret=malloc(128);
	fscanf(file, "%128s", ret);
//	printf(ret);
	return ret;
}

char* prevHashFor(char* fileName) {
	char* buf=malloc(128);
	char* fileId=getFileId(fileName);
	if(strcmp(fileId,"")) {
		sprintf(buf,"SELECT hash FROM Endring WHERE fil_id=%s", fileId);
		sql_query(buf);
	}
	return "";
}

int fileChanged(char* fileName) {
	return strcmp(prevHashFor(fileName), hash(fileName));
}
