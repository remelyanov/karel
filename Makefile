# variables
CC=gcc
CFLAGS= 
LDLIBS=-lkarel -lcurses
OUTPUT=karel

# targets
all: karel.c
	$(CC) $(CFLAGS) karel.c $(LDLIBS) -o $(OUTPUT)

karel: karel.c
	$(CC) $(CFLAGS) karel.c $(LDLIBS) -o $(OUTPUT)

k1: k1.c
	$(CC) $(CFLAGS) karel.c $(LDLIBS) -o k1

