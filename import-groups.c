#include<stdlib.h>
#include "group.h"

int main() {
	FILE* fp=fopen("/etc/group", "r");

	if(fp==NULL) exit(1);

	char* line=NULL;
	size_t len=0;
	ssize_t read;
	while((read=getline(&line,&len,fp))!=-1) {
//		printf("%s", line);
		char* name,*password,*id,*users;
//		sscanf(line, "%s:%s:%d:%d:%s:%s",uname,pw,uid,gid,name,home,shell);
		name=strsep(&line,":");
		password=strsep(&line,":");
		id=strsep(&line,":");
		users=strsep(&line,":");
		printf("%s\n",name);
//		add_user(char* navn, char* epost, char* tlf, char* adresse, char* byen, char* postkode, char gender)
		add_group(name);
	}
}
