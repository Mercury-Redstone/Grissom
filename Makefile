CC=gcc
CFLAGS=-c `mysql_config --cflags`
LDFLAGS=`mysql_config --libs`
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
all: main
.c.o: 
	echo "Compiling C-files"
	gcc -c $(CFLAGS) $< -l $(LDFLAGS) -l $@
