CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:			test0 testPut

list.o: 		list.c list.h
				gcc $(CFLAGS) -c list.c

test0.o:		test0.c list.h
				gcc $(CFLAGS) -c test0.c

test0:			test0.o list.o
				gcc $(CFLAGS) test0.o list.o -o test0

testPut.o:  testPut.c list.h
				gcc $(CFLAGS) -c testPut.c

testPut:		testPut.o list.o
				gcc $(CFLAGS) testPut.o list.o -o testPut

clean:			
				rm -f *.o test0
