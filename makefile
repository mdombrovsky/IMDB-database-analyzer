CC=gcc
CFLAGS=-Wall -ansi -g -pedantic

all: a3

a3: a3.o name.o binary.o common.o principals.o title.o
	$(CC) $(CFLAGS) a3.o name.o binary.o common.o principals.o title.o -o a3

a3.o: main.c common.h binary.h name.h principals.h title.h
	$(CC) $(CFLAGS) -c main.c -o a3.o

binary.o: binary.c common.h
	$(CC) $(CFLAGS) -c binary.c -o binary.o

common.o: common.c
	$(CC) $(CFLAGS) -c common.c -o common.o

name.o: name.c binary.h common.h
	$(CC) $(CFLAGS) -c name.c -o name.o

principals.o: principals.c binary.h common.h
	$(CC) $(CFLAGS) -c principals.c -o principals.o

title.o: title.c binary.h common.h
	$(CC) $(CFLAGS) -c title.c -o title.o


clean:
	rm *.o