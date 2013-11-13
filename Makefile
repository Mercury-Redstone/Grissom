all: 
	gcc -c `mysql_config --cflags` main.c
	gcc -o main-exec main.o `mysql_config --libs`
