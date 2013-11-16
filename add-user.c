#include "user.h"
int main(int argc, char** argv) {
	assert(argc==8);
	sql_init();
	add_user(argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7][0]);
}
