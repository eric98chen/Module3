CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:			hash.o #chrisTest test1to4

hash.o: 			hash.c hash.h
					gcc $(CFLAGS) -c hash.c

queue.o:			queue.c queue.h
					gcc $(CFLAGS) -c queue.c
#chrisTest.o:	chrisTest.c queue.h
#					gcc $(CFLAGS) -c chrisTest.c

#chrisTest:		chrisTest.o queue.o
#					gcc $(CFLAGS) chrisTest.o queue.o -o chrisTest

clean:			
					rm -f *.o #chrisTest test1to4
