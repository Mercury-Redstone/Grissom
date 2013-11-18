#include "group.h"

int main(int argc, char** argv) {
	sql_init();
	add_group(argv[1]);
}
