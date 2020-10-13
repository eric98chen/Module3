CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:			test1to3 

hash.o: 			hash.c hash.h queue.h
					gcc $(CFLAGS) -c hash.c

queue.o:			queue.c queue.h 
					gcc $(CFLAGS) -c queue.c

test1to3.o:	test1to3.c hash.h queue.h
					gcc $(CFLAGS) -c test1to3.c

test1to3:		test1to3.o hash.o queue.o
					gcc $(CFLAGS) test1to3.o hash.o queue.o -o test1to3

clean:			
					rm -f *.o test1to3 
