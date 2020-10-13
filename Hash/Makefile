CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:			test1to3 testHapply testHsearch

hash.o: 			hash.c hash.h queue.h
					gcc $(CFLAGS) -c hash.c

queue.o:			queue.c queue.h 
					gcc $(CFLAGS) -c queue.c

test1to3.o:	test1to3.c hash.h queue.h
					gcc $(CFLAGS) -c test1to3.c

test1to3:		test1to3.o hash.o queue.o
					gcc $(CFLAGS) test1to3.o hash.o queue.o -o test1to3

testHapply.o:	testHapply.c hash.h queue.h
					gcc $(CFLAGS) -c testHapply.c

testHapply:		testHapply.o hash.o queue.o
					gcc $(CFLAGS) testHapply.o hash.o queue.o -o testHapply

testHsearch.o:	testHsearch.c hash.h queue.h
					gcc $(CFLAGS) -c testHsearch.c

testHsearch:		testHsearch.o hash.o queue.o
					gcc $(CFLAGS) testHsearch.o hash.o queue.o -o testHsearch

clean:			
					rm -f *.o test1to3 testHapply testHsearch
