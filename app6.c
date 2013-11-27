#include "file.h"
#include "hash.h"
#include "revision.h"

int main() {
	char **files=checkableFiles();

	char* file;

	while((file=(*files++))!=NULL) {
		char* path=getFilePath(file);
		printf("%s:%s:%d\n",file,path,fileChanged(path));
	}
}
