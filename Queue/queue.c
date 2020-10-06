/* queue.c -- implementation of queue.h
 *
 * Author: Eric Chen
 * Created: Mon, Oct 5, 2020
 * Version:
 *
 * Description: functions on queue_t object
*/ 

#include <stdint.h>
#include <stdbool.h>


/* the queue representation is hidden from users of the module */
typedef void queue_t;

static queue_t *front, *back; //front and back pointers for queue

/* create an empty queue */
queue_t* qopen(void) {
	queue_t *qp;
	front = NULL; //initialize front and back as NULL since queue is still empty
	back = NULL;
	printf("Empty queue created\n");
	return qp;
}       


/* deallocate a queue, frees everything in it */
void qclose(queue_t *qp) {
	//loop through all elements into
	//free each one
	queue_t *p;
	for (p=front; p!=NULL; p=p->next) {
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
		back->next = elementp;	//joins new element into list
		back = elementp;		//set new element as back of queue
	}
	
	printf("Element added to list\n");
	return 0;
}


/* get the first first element from queue, removing it from the queue */
void* qget(queue_t *qp) {

	if (front==NULL) {
		printf("Queue is empty\n");
		return NULL;
	}
	else {
		printf("First element removed and returned\n");
		queue_t *firstElemet = front; //need this to keep track of first element as we update front
		front = front->next; //effectively removes first element from queue
		return firstElement; //returns first element
	}
}


/* apply a function to every element of the queue */
void qapply(queue_t *qp, void (*fn)(void* elementp));


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

