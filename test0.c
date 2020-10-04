/* putTest.c -- tests put() function in list.h interface
 *
 * Author: Eric Chen
 * Created: Sun Sep 27 13:27:10 2020
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



/* fn() takes a car_t pointer and sets year of car_t to 0
 * returns nothing
 */
void fn(car_t *cp) {
	cp->year = 0;
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

	//TEST LGET() FUNCTION
	car_t *first = lget(); //removes and returns pointer to first car in list
	printf("First car is: %s, %f, %d\n",first->plate, first->price, first->year);
	printf("lget success\n");
	
	
	
	//lapply(fn); //applies function fn to every car in list


	

	return 0;
}




 
 
