#include "file.h"
int main(int argc, char** argv) {
	assert(argc==7);
//	sql_init();
	add_file(argv[1],argv[2],argv[3],argv[4],argv[5],atoi(argv[6]));
}
