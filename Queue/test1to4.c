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

	//TEST QOPEN
	queue_t *qp;
	qp = qopen(); //returns pointer to newly created queue_t object
	
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
	
	return 0;
}




 
