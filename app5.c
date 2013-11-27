#include "file.h"
#include "hash.h"
#include "revision.h"

int main() {
	char **files=checkableFiles();

	char* file;

	while((file=(*files++))!=NULL) {
		char* path=getFilePath(file);
		printf("%s: ",path);
		char* fHash=hash(path);
		if(fileChanged(path)) {
			printf(" CHANGED\n");
			add_current_revision(file,fHash);
		}
		else printf(" NOT CHANGED\n");
	}
}
