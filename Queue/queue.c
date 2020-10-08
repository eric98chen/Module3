/* queue.c -- implementation of queue.h
 *
 * Author: Eric Chen
 * Created: Mon, Oct 5, 2020
 * Version:
 *
 * Description: functions on queue_t object
*/ 

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "queue.h"
#include <string.h>
#include <stdlib.h>


/* the queue representation is hidden from users of the module */
struct queue_t {
	struct car_t *front;
	struct car_t *back;
};


/* create an empty queue */
queue_t* qopen(void) {
	struct queue_t *qp;
	qp->front = NULL;
	qp->back = NULL;
	printf("Empty queue created\n");
	return qp;
}       


/* deallocate a queue, frees everything in it */
void qclose(queue_t *qp) {
	//loop through all elements into
	//free each one
	struct car_t *p;
	
	for (p=qp->front; p!=NULL; p=p->next) {
		free(p);
	}
	
    
	printf("Queue deallocated\n");
}


/* put element at the end of the queue
 * returns 0 if successful; nonzero otherwise 
 */
int32_t qput(queue_t *qp, void *elementp) {
	
	if (qp == NULL) {	
		printf("Queue is NULL\n");
		return 1;
	}
	
	if (elementp == NULL) {	
		printf("Object passed in is NULL\n");
		return 1;
	}
	
	if (back == NULL) {		//if queue empty
		back = elementp;	//assignment works because both objects are of type void within this code
		front = elementp;
	}
	else {						//if list non-empty
		back->next = elementp;	//joins new element into list. 
								//Works bc at this point, back should already be assigned to elementp object type
		back = elementp;		//set new element as back of queue
	}
	
	printf("Element added to list\n");
	return 0;
}


/* get the first first element from queue, removing it from the queue */
void* qget(queue_t *qp) {

	if (qp->front==NULL) {
		printf("Queue is empty\n");
		return NULL;
	}
	else {
		printf("First element removed and returned\n");
		queue_t *firstElement = front; //need this to keep track of first element as we update front
		front = front->next; //effectively removes first element from queue
		return firstElement; //returns first element
	}
}


/* apply a function to every element of the queue */
void qapply(queue_t *qp, void (*fn)(void* elementp)) {

	if (fn==NULL) {
		printf("Error. Function is NULL\n");
	}
	if (qp->front==NULL) {
		printf("Queue is empty\n");
	}
	else {
		printf("Applying function to every element of the queue.\n");
		queue_t *p; //create pointer to start looping through queue elements
		for (p=qp->front; p!=NULL; p=p->next) { //loops through queue and applies function fn to each item
			fn(p);
		}
	}

}


/* search a queue using a supplied boolean function
 * skeyp -- a key to search for
 * searchfn -- a function applied to every element of the queue
 *          -- elementp - a pointer to an element
 *          -- keyp - the key being searched for (i.e. will be 
 *             set to skey at each step of the search
 *          -- returns TRUE or FALSE as defined in bool.h
 * returns a pointer to an element, or NULL if not found
 */
void* qsearch(queue_t *qp, 
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp);


/* search a queue using a supplied boolean function (as in qsearch),
 * removes the element from the queue and returns a pointer to it or
 * NULL if not found
 */
void* qremove(queue_t *qp,
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp);


/* concatenatenates elements of q2 into q1
 * q2 is dealocated, closed, and unusable upon completion 
 */
void qconcat(queue_t *q1p, queue_t *q2p);

