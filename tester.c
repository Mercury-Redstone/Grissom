#include <stdio.h>
#include "sql.h"
#include "user.h"

int main(int argc, char **argv)
{
	printf("sql_init\t");
	sql_init();
	printf("Ok\n");

	printf("sql_query\t");
	MYSQL_RES* result=sql_query("SELECT * FROM Bruker;");
	printf("Ok\n");

	printf("add_user\t");
	//INSERT INTO Bruker (navn, epost, tlf, adresse, byen, postkode, gender) VALUES (,,,,,,);"
	add_user("test","test","00000000","test","test","0000",'M');
	printf("Ok\n");
	return 0;
}
