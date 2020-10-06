/* queueTest.c -- tests functions of queue.h interface
 *
 * Author: Eric Chen
 * Created: Mon Oct 5, 13:27:10 2020
 * Version:
 *
 * Description: returns 0 if success, nonzero if error
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
	struct car *next;
	char plate[MAXREG];
	double price;
	int year;
} car_t;
 

/* makeCar(): creates a car object
 * returns 0 if successful; nonzero otherwise 
 */
car_t* make_car(car_t *next, char *platep, double price, int year) {
	
	car_t *cp;
	
	if ( !(cp = (car_t*)malloc(sizeof(car_t))) ) { 	//check if enough space in memory for car_t*
		printf("Error: malloc failed allocating car\n");
		return NULL;
	}
	cp->next = next;
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

	//MAKE QUEUE
	queue_t *qp;
	car_t *cp1, *cp2, *first;
	
	qp = qopen(); //returns pointer to newly created queue_t object
	
	cp1 = make_car(NULL,"2LLE50",20000.0,2014); //returns pointer to newly created car_t object
	cp2 = make_car(NULL,"NNHS16",30000.0,2016);
	
	//TEST QPUT()
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
	

	return 0;
}




 
 
