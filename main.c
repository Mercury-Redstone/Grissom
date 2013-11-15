#include <stdio.h>
#include "sql.h"

int main(int argc, char **argv)
{
	printf("sql_init\t");
	sql_init();
	printf("Ok\n");
	return 0;
}
