/* putTest.c -- tests put() function in list.h interface
 *
 * Author: Chris Lyke
 * Created: 
 * Version:
 *
 * Description: returns 0 if success, nonzero if error
 *
 */
 
#include <stdio.h>
#include "list.h"
#include <inttypes.h> 
#include <stdlib.h> //needed for malloc
#include <string.h>
 

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


int main (void) {

	//TEST LPUT() FUNCTION
	car_t *cp1 = make_car(NULL,"2LLE50",20000.0,2014);
	car_t *cp2 = make_car(NULL,"NNHS16",30000.0,2016);

	uint32_t lput_return1 = lput(cp1); //adds cp1 to front of list
	uint32_t lput_return2 = lput(cp2); ///adds cp2 to front of list
	
	if (lput_return1==0 && lput_return2==0) {
		printf("lput success\n"); //check if lput function worked
	}
	else {
		printf("lput failed\n");
	}

	return 0;
}

