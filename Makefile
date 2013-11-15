CC=gcc
CFLAGS=-c `mysql_config --cflags`
LDFLAGS=`mysql_config --libs`
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)

all: main add-users add-groups add-rights add-files calculate-hashes
.c.o: 
	gcc -c $(CFLAGS) $< -l $(LDFLAGS) -l $@
