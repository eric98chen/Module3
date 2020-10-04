CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:			test0 testPut testGet testApply

list.o: 		list.c list.h
				gcc $(CFLAGS) -c list.c

test0.o:		test0.c list.h
				gcc $(CFLAGS) -c test0.c

test0:			test0.o list.o
				gcc $(CFLAGS) test0.o list.o -o test0

testPut.o:  	testPut.c list.h
				gcc $(CFLAGS) -c testPut.c

testPut:		testPut.o list.o
				gcc $(CFLAGS) testPut.o list.o -o testPut
				
testGet.o:  	testGet.c list.h
				gcc $(CFLAGS) -c testGet.c

testGet:		testGet.o list.o
				gcc $(CFLAGS) testGet.o list.o -o testGet
				
testApply.o:  	testApply.c list.h
				gcc $(CFLAGS) -c testApply.c

testApply:		testApply.o list.o
				gcc $(CFLAGS) testApply.o list.o -o testApply

clean:			
				rm -f *.o test0 testPut testGet testApply
