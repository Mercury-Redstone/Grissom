#include <stdio.h>
#include "sql.h"

int main(int argc, char **argv)
{
	printf("sql_init\t");
	sql_init();
	printf("Ok\n");

	printf("sql_query\t");
	MYSQL_RES* result=sql_query("SELECT * FROM Bruker;");
	printf("Ok\n");
	return 0;
}
