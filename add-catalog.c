#include "catalog.h"

int main(int argc, char** argv) {
	sql_init();
	add_catalog(argv[1]);
}
