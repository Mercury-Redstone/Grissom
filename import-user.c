#include<stdlib.h>
#include "user.h"

int main() {
	FILE* fp=fopen("/etc/passwd", "r");

	if(fp==NULL) exit(1);

	char* line=NULL;
	size_t len=0;
	ssize_t read;
	while((read=getline(&line,&len,fp))!=-1) {
//		printf("%s", line);
		char* uid,*gid,*uname, *name, *pw, *shell, *home;
//		sscanf(line, "%s:%s:%d:%d:%s:%s",uname,pw,uid,gid,name,home,shell);
		uname=strsep(&line,":");
		pw=strsep(&line,":");
		uid=strsep(&line,":");
		gid=strsep(&line,":");
		name=strsep(&line,":");
		home=strsep(&line,":");
		shell=strsep(&line,":");
		printf("%s\n",name);
//		add_user(char* navn, char* epost, char* tlf, char* adresse, char* byen, char* postkode, char gender)
		add_user(name,uname,"","","","",'M');
	}
}
