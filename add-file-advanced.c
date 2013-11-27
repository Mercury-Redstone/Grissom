#include "file.h" 
#include "user.h"
#include "group.h"
#include <stdio.h> 
#include <string.h> 

int main(void) {
	char *inp[6];
	char temp[100];
	static const char *Nameholder[] = {"Navn på fil:", "Navn til bruker:", "Navn til gruppe:", "Navn til katalog:", "Navn til eier:", "Skal filen overvåkes 1 for ja:"};

	for(;;) {
		int i = 0;
		while (i<6) {
			printf("%s", Nameholder[i]);
			gets(temp);
			inp[i] = strdup(temp);

			i++;
		}
		char* filNavn=inp[0], *uid=getUid(inp[1]), *gid=getGid(inp[2]), *cid=getCatalogId(inp[3]), *euid=getUid(inp[4]);
		add_file(filNavn,uid,gid,cid,euid,atoi(inp[5]));
	}
}
