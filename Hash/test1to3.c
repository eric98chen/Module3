/* test1to3.c -- tests hopen, hclose, and hput functions in hash.h interface
 *
 * Author: Chris Lyke
 * Created: Oct 12
 * Version:
 *
 * Description: returns 0 if success, nonzero if fail
 *
 */
 
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "hash.h"
 
 
#define MAXREG 10

/* the representation of a car */
typedef struct car {
	char plate[MAXREG];
	double price;
	int year;
} car_t;
 
/* makeCar(): creates a car object */
car_t* make_car(char *platep, double price, int year) {
	
	car_t *cp;
	if ((cp = (car_t*)malloc(sizeof(car_t))) == NULL) { 	//check if enough space in memory for car_t*
		printf("Error: malloc failed allocating car\n");
		return NULL;
	}
	printf("car malloc succesful\n");
	strcpy(cp->plate, platep);
	cp->price = price;
	cp->year = year;
	return cp;
}


/* the representation of a student */
typedef struct student {
	char name[MAXREG];
	int year;
} student_t;

/* make_student(): creates a student object */
student_t* make_student(char *namep, int year) {
	
	student_t *sp;
	if ((sp = (student_t*)malloc(sizeof(student_t))) == NULL) { 	//check if enough space in memory for car_t*
		printf("Error: malloc failed allocating car\n");
		return NULL;
	}
	printf("student malloc succesful\n");
	strcpy(sp->name, namep);
	sp->year = year;
	return sp;
}


/* fn() takes a car_t pointer and sets year of car_t to 0
 * returns nothing
 */
void fn(car_t *cp) {
	cp->year = 0;
}
	
 
int main (void) {

	int32_t result;
	uint32_t hsize = 20;

	hashtable_t *hp; //agnostic hashtable, can hold cars and students
	hashtable_t *hpNULL = NULL; //dumby hashtable
	
	car_t *cp1, *cp2, *cp3;
	car_t *cpNULL = NULL;
	car_t *cpFirst, *cpSecond, *cpThird;
	
	student_t *sp1, *sp2;
	student_t *spFirst, *spSecond;
	
	cp1 = make_car("car1", 1.0, 1910); //declare all cars
	cp2 = make_car("car2", 4.0, 1940);
	cp3 = make_car("car3", 9.0, 1990);
	
	sp1 = make_student("Eric",2021); //declare all students
	sp2 = make_student("David",2020); 
	

	// TEST HOPEN
	hp = hopen(hsize); //returns pointer to newly created hashtable_t
	if (hp == NULL) {
		printf("hopen returns NULL when should have opened successfully\n");
		exit(EXIT_FAILURE);
	}
	else printf("hopen successful\n\n");
	
	
	
	//int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen) {
	//
	// TEST HPUT
	if((result = hput(hp, cp1, cp1->plate, strlen(cp1->plate)) == 0){ //testing qput with NULL element
		printf(">>ISSUE: qput succeeded with NULL element when should have failed\n");
		exit(EXIT_FAILURE);
	}
	else printf(">> qput (cpNULL) occurred as expected\n");
	
	/*sp1 = make_student("Eric",2021); //declare all students
	sp2 = make_student("David",2020); 
	
	result = 0;
	result += qput(qp, (void*)cp1); //put to empty queue (returns 1 if any error)
	result += qput(qp, (void*)cp2); //put into non-empty queue
	result += qput(qp, (void*)cp3);
	result += qput(qp, (void*)sp1);	//put different objects into same queue
	result += qput(qp, (void*)sp2);

	if ( result > 0 ) {
		printf("qput error \n");
		qclose(qp);	//need to free memory of everything already put into queue
		exit(EXIT_FAILURE);
	}
	else printf("qput cases successful\n\n");
	
	cp1->year = 0000; //can directly alter the data stored queue from this main code
 	*/
 
	
	
	// TEST HCLOSE
	hclose(hpNULL); //close a NULL queue
	printf(">>hclose (hpNULL) occurred as expected\n");

	hclose(hp);
	printf("hclose successful\n\n");
	
	
	exit(EXIT_SUCCESS);
}

 
