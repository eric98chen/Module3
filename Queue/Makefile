CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:			chrisTest test1to4 testQapply

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

testQapply.o:	testQapply.c queue.h
					gcc $(CFLAGS) -c testQapply.c

testQapply:		testQapply.o queue.o
					gcc $(CFLAGS) testQapply.o queue.o -o testQapply

clean:			
					rm -f *.o chrisTest test1to4 testQapply
