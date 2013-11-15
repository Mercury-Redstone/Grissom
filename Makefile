CC=gcc
CFLAGS=`mysql_config --cflags`
LDFLAGS=`mysql_config --libs`
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLES=$(SOURCES:.c=)

.PHONY: all

all: $(EXECUTABLES)
.c.o: sql.h
	$(CC) $(CFLAGS) $< -l $(LDFLAGS) -l $@
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLES)
