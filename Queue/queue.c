/* queue.c -- implementation of queue.h
 *
 * Author: Eric Chen
 * Created: Mon, Oct 5, 2020
 * Version:
 *
 * Description: functions on queue_t object
*/ 

#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* defines each node of a queue */
typedef struct node {
	struct node *next;	//point to next node
	void *data;			//holds data of node
} node_t;


/* creates new node */
static node_t* make_node(void *elementp) {
	node_t *p;
	
	if (elementp == NULL) {	
		return NULL;
	}
	if ((p = (node_t*)malloc(sizeof(node_t))) == NULL){
		return NULL;
	}
	printf("node malloc success\n");
	p->data = elementp; //both of type void
	p->next = NULL;
	return p;
}

/* the queue representation is hidden from users of the module */
typedef struct qheader {
	node_t *front;
	node_t *back;
} qheader_t;


/* create an empty queue */
queue_t* qopen(void) {
	qheader_t *qp;
	if ( (qp = (qheader_t*)malloc(sizeof(qheader_t))) == NULL ) 
		return NULL;	
	qp->front = NULL;
	qp->back = NULL;
	printf("queue malloc success\n");
	printf("New queue created\n");
	return (queue_t*)qp;
}       


/* deallocate a queue, frees everything in it */
void qclose(queue_t *qp) {
	node_t *prev;
	node_t *curr;
	qheader_t *hp;

	//include case where qp == NULL
	if (qp == NULL) {
		printf("Error: queue is NULL\n");
	}
	else {
		hp = (qheader_t*)qp; //need to coerce void queue_t object into local qheader_t object
		curr = hp->front;
		while (curr != NULL){	//loops through and frees data and *next pointer stored in each node
			prev = curr;
			if(prev->data != NULL){
				free(prev->data);//free data stored
			}
			curr = prev->next;
			free(prev);	//free *next pointer
		}
		free(hp);
		printf("The queue has been freed\n");
	}
		
}


/* put element at the end of the queue
 * returns 0 if successful; nonzero otherwise 
 */
int32_t qput(queue_t *qp, void *elementp) {

	qheader_t *hp;
	node_t *p;
	
	if (qp == NULL) {	
		printf("Error: queue is NULL\n");
		return 1;
	}
	
	if (elementp == NULL) {	
		printf("Error: object passed in is NULL\n");
		return 1;
	}
	
	hp = (qheader_t*)qp;
	p = make_node(elementp);
	
	if (hp->back == NULL) {		//if queue empty
		hp->back = p;			//both objects are type void
		hp->front = p;
	}
	else {						//if list non-empty
		hp->back->next = p;		//joins new element into list. 
		hp->back = p;			//set new element as back of queue
	}
	
	printf("Element added to list\n");
	return 0;
}



/* get the first element from queue, removing it from the queue */
void* qget(queue_t *qp) {
	qheader_t *hp;
	node_t *p;
	void *tmp;

	if (qp == NULL) {	
		printf("Error: queue is NULL\n");
		return NULL;
	}
	
	hp = (qheader_t*)qp;
	
	if (hp->front==NULL) {
		printf("Error: queue is empty\n");
		return NULL;
	}
	
	p = hp->front; //need this to keep track of first element as we update front
	hp->front = hp->front->next; //effectively removes first element from queue

	tmp = p->data; //keep track of data stored in first element
	//if(p->data != NULL){  
	//	free(p->data); //cant free data memory here. Causes memory issue. Instead, free in test main
	//}
	free(p); //frees *next pointer
	
	printf("First element removed and returned\n");
	return tmp; //returns data stored in first element
}


//NOTE: commenting out functions below bc compiler found errors but I'm only trying to test first 4 functions

/* apply a function to every element of the queue */

/*void qapply(queue_t *qp, void (*fn)(void* elementp)) {
	qheader_t *hp;
	node_t *p;
	
	if (qp == NULL) {	
		printf("Queue is NULL\n");
	}
	hp = (qheader_t*)qp;
	
	if (fn==NULL) {
		printf("Error. Function is NULL\n");
	}
	if (hp->front==NULL) {
		printf("Queue is empty\n");
	}
	else {
		printf("Applying function to every element of the queue.\n");

		p = hp->front;
		while (p != NULL){
			if(p->data != NULL){
				fn(p->data);
			}
			p = p->next;
		}
	}
}
*/



/* search a queue using a supplied boolean function
 * skeyp -- a key to search for
 * searchfn -- a function applied to every element of the queue
 *          -- elementp - a pointer to an element
 *          -- keyp - the key being searched for (i.e. will be 
 *             set to skey at each step of the search
 *          -- returns TRUE or FALSE as defined in bool.h
 * returns a pointer to an element, or NULL if not found
 */
/*void* qsearch(queue_t *qp, 
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp){
	qheader_t *hp;
	node_t *p;
	bool result;
	
	if (qp == NULL) {	
		printf("Queue is NULL\n");
		return NULL;
	}
	hp = (qheader_t*)qp;
	
	if (searchfn==NULL) {
		printf("Error. Function is NULL\n");
		return NULL;
	}
	if (hp->front==NULL) {
		printf("Queue is empty\n");
		return NULL;
	}
	else {
		printf("Applying function to every element of the queue.\n");

		p = hp->front;
		while (curr != NULL){
			if(p->data != NULL){
				if ((result = searchfn(p->data, skeyp)) == true){
					return(p);
				}
			}
			p = p->next;
		}
		return NULL;
	}						
}
*/

/* search a queue using a supplied boolean function (as in qsearch),
 * removes the element from the queue and returns a pointer to it or
 * NULL if not found
 */
/*void* qremove(queue_t *qp,
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp){
	qheader_t *hp;
	node_t *prev;
	node_t *curr;
	bool result;
	void *tmp;
	
	if (qp == NULL) {	
		printf("Queue is NULL\n");
		return NULL;
	}
	hp = (qheader_t*)qp;
	
	if (searchfn==NULL) {
		printf("Error. Function is NULL\n");
		return NULL;
	}
	if (hp->front==NULL) {
		printf("Queue is empty\n");
		return NULL;
	}
	else {
		printf("Applying function to every element of the queue.\n");

		curr = hp->front;
		while (curr != NULL){
			prev = curr;
			if(prev->data != NULL){
				if ((result = searchfn(prev->data, skeyp)) == true){
					tmp = prev->data;
					//if(prev->data != NULL){ //cant free data here. Causes memory issue. Instead, free in test main
					//	free(prev->data);
					//}
					free(prev); //OK to free prev, bc refers to the node_t *next pointer, not the data returned
					printf("Searched element removed and returned\n");
					return tmp; //returns first element
				}
			}
			curr = prev->next;
		}
		return NULL;
	}						
}
*/


/* concatenatenates elements of q2 into q1
 * q2 is dealocated, closed, and unusable upon completion 
 */
/*void qconcat(queue_t *q1p, queue_t *q2p){
	node_t *p;
	qheader_t *hp1;
	qheader_t *hp2;
	node_t *curr;

	if ((q1p == NULL) || (q2p == NULL) {	
		printf("Queue is NULL\n");
	}
	
	hp1 = (qheader_t*)q1p;
	hp2 = (qheader_t*)q2p;
	
	if ((hp1->front==NULL) || (hp1->front==NULL)) {
		printf("Queue is empty\n");
		return NULL;
	}

	curr = hp2->front;
	while (curr != NULL){
		p = make_node(curr->data);
		hp1->back->next = p;
		hp1->back = p;
		curr = curr->next;
	}

	qclose(q2p);
}
*/




