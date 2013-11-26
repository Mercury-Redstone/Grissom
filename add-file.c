#include "file.h"
int main(int argc, char** argv) {
	assert(argc==7);
//	sql_init();
	add_file(argv[1],atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),atoi(argv[5]),atoi(argv[6]));
}
