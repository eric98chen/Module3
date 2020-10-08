CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:					chrisTest

queue.o: 		queue.c queue.h
					gcc $(CFLAGS) -c queue.c
							
test1to4.o:		test1to4.c queue.h
					gcc $(CFLAGS) -c test1to4.c

test1to4:		test1to4.o queue.o
					gcc $(CFLAGS) test1to4.o queue.o -o test1to4

chrisTest.o:	chrisTest.c queue.h
					gcc $(CFLAGS) -c chrisTest.c

chrisTest:		chrisTest.o queue.o
					gcc $(CFLAGS) chrisTest.o queue.o -o chrisTest

clean:			
					rm -f *.o chrisTest
