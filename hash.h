#include <stdio.h>

char* hash(char* fileName) {
	char* cmd=malloc(strlen("sha512sum ")+strlen(fileName));
	sprintf(cmd, "sha512sum %s", fileName);
	FILE* file=popen(cmd, "r");
	char* ret=malloc(128);
	fscanf(file, "%128s", ret);
//	printf(ret);
	return ret;
}
