CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:			test1to4

queue.o: 		queue.c queue.h
				gcc $(CFLAGS) -c queue.c

test1to4.o:		test1to4.c queue.h
				gcc $(CFLAGS) -c test1to4.c

test1to4:		test1to4.o queue.o
				gcc $(CFLAGS) test1to4.o queue.o -o test1to4

clean:			
				rm -f *.o test1to4
