CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:			test0

list.o: 		list.c list.h
				gcc $(CFLAGS) -c list.c

test0.o:		test0.c list.h
				gcc $(CFLAGS) -c test0.c

test0:			test0.o list.o
				gcc $(CFLAGS) test0.o list.o -o test0

clean:			
				rm -f *.o test0
