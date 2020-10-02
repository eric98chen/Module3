/* list.c -- implements interface for list.h
 *
 *
 * Author: Eric Chen
 * Created: Thursday, Oct 1, 2020
 * Version:
 *
 * Description: functions on car_t object
 
 
*/ 

#include <stdio.h>
#include <stdint.h>
#include "list.h"
#include <string.h>

#define MAXREG 10

static car_t *front = NULL:

/* the representation of a car */
typedef struct car {
	struct car *next;
	char plate[MAXREG];
	double price;
	int year;
} car_t;


/* put(): place a car at the beginning of the list
 * returns 0 if successful; nonzero otherwise 
 */
int32_t lput(car_t *cp) {

	if (front == NULL) {	//if list empty
		front=cp;
		return 0;
	}
	else if {				//if list non-empty
		cp->next=front;	 	//set cp->next to point to original front
		front=cp;			//set cp as the new front
		return 0;
	}
	else {
		return 1;
	}

}


/* get(): remove and return the first car in the list;
 * return NULL if the list is empty
 */
car_t *lget() {

	car_t firstCar;
	
	if (front == NULL) {
		return NULL;	
	}
	else {
		firstCar = *front; //grabs car_t referenced by front
	}
	
	return firstCar;
}



/* apply a function to every car in the list */
void lapply(void (*fn)(car_t *cp)) {
	
	car_t *p; //create pointer to start looping through car_t list
	
	for (p=front; p!=NULL; p=p->next) { //loops through list and applies function fn to each item
		fn(p);
	}

}



/* remove(): find, remove, and return any car with
 * the designated plate; return NULL if not present
 */
car_t *lremove(char *platep) { 
	
	car_t *p, *f; //pointers to help loop through car_t list
	
	for (p=front; p!=NULL; p=p->next) { //loop through list and find any car with matching plate	
		
		if (strcmp(p->plate,*platep)) { 
			if (p==front) {
				front = p->next; //if first item matches, have front point to second item
				return p; //return pointer to matching item
			}
			else { 	//assuming first item is not a match
				f->next = p->next; //effectively removes matching item from list. If p is last item, the f->next becomes NULL
				return p; //return pointer to matching item
				//PROBLEM: only returns first matching car. Do we need to return pointer to linked-list of multiple matches?
			}
		}
		
		f = p;
	}
	
	return NULL; //if goes through entire list and no matches occur, then return NULL
}
