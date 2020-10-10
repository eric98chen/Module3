/* queueTest.c -- tests qopen, qclose, qput, and qget functions in queue.h interface
 *
 * Author: Eric Chen
 * Created: Tues Oct 6
 * Version:
 *
 * Description: returns 0 if success, nonzero if fail
 *
 */
 
#include <stdio.h>
#include "queue.h"
#include <inttypes.h> 
#include <stdlib.h> //needed for malloc
#include <string.h>
 
 
#define MAXREG 10

/* the representation of a car */
typedef struct car {
	char plate[MAXREG];
	double price;
	int year;
} car_t;
 

/* makeCar(): creates a car object
 * returns 0 if successful; nonzero otherwise 
 */
car_t* make_car(char *platep, double price, int year) {
	
	car_t *cp;
	if ((cp = (car_t*)malloc(sizeof(car_t))) == NULL) { 	//check if enough space in memory for car_t*
		printf("Error: malloc failed allocating car\n");
		return NULL;
	}
	strcpy(cp->plate, platep);
	cp->price = price;
	cp->year = year;
	return cp;
}


/* fn() takes a car_t pointer and sets year of car_t to 0
 * returns nothing
 */
void fn(car_t *cp) {
	cp->year = 0;
}
	
 
int main (void) {

	queue_t *qp; //agnostic queue
	queue_t *qpNULL = NULL;
	car_t *cp1;
	car_t *cp2;
	car_t *cp3;
	car_t *cpNULL = NULL;
	car_t *cpFirst, *cpSecond, *cpThird;
	int32_t result;

	
	//TEST QOPEN
	qp = qopen(); //returns pointer to newly created queue_t
	printf("qopen successful\n\n");


	//TEST QPUT
	if((result = qput(qp, (void*)cpNULL)) != 0){ //put a NULL element
		printf(">>qput (cpNULL) occurred as expected\n");
	}
	
	cp1 = make_car("car1", 1.0, 1910); //declare all cars
	cp2 = make_car("car2", 4.0, 1940);
	cp3 = make_car("car3", 9.0, 1990);
	
	if((result = qput(qp, (void*)cp1)) != 0){ //Put to empty queue. Returns 1 if any error
		printf("qput1 failed\n");
		exit(EXIT_FAILURE);
	}
	
	if((result = qput(qp, (void*)cp2)) != 0){ //Put into non-empty queue
		printf("qput2 failed\n");
		exit(EXIT_FAILURE);
	}
	
	if((result = qput(qp, (void*)cp3)) != 0){
		printf("qput3 failed\n");
		exit(EXIT_FAILURE);
	}
	printf("qput cases successful\n\n");
 
 
 	//TEST QPGET
 	cpNULL =(car_t*)qget(qpNULL); //get from NULL queue
 	printf(">>qget (qpNULL) occurred as expected\n");

	cpFirst = (car_t*)qget(qp); //get from queue. Need to coerce void pointer into car_t pointer
	cpSecond = (car_t*)qget(qp); 
	cpThird = (car_t*)qget(qp);	//get last element from queue
	cpNULL = (car_t*)qget(qp); //get from empty queue

	printf("Car 1: plate = %s, price = %f, year = %d\n", cpFirst->plate, cpFirst->price, cpFirst->year);
	printf("Car 2: plate = %s, price = %f, year = %d\n", cpSecond->plate, cpSecond->price, cpSecond->year);
	printf("Car 3: plate = %s, price = %f, year = %d\n", cpThird->plate, cpThird->price, cpThird->year);
	printf("qget successful\n\n");
	
	
	//TEST QCLOSE
	qclose(qpNULL); //close a NULL queue
	printf(">>qclose (qpNULL) occurred as expected\n");

	qclose(qp);
	printf("qclose successful\n");

	exit(EXIT_SUCCESS);
}

	
/*	//TEST QPUT
	car_t *cp1, *cp2, *first;
	cp1 = make_car(NULL,"2LLE50",20000.0,2014); //returns pointer to newly created car_t object
	cp2 = make_car(NULL,"NNHS16",30000.0,2016);
	
	uint32_t qput_return = qput(qp,(void*)cp1); //puts car_t object into queue_t object

	if (qput_return==0) {
		printf("qput success\n"); //check if qput function worked
	}
	else {
		printf("qput failed\n");
	}
	

	//TEST QGET()
	first = (car_t*)qget(); //qget() returns pointer to object of type void, so need to coerce into car_t type
	printf("First car is: %s, %f, %d\n",first->plate, first->price, first->year);
	printf("qget success\n");
	
*/
 
