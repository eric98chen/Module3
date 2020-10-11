/* 
 * hash.c -- implements a generic hash table as an indexed set of queues.
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "hash.h"

#define get16bits(d) (*((const uint16_t *) (d)))


/* the hash table representation is hidden from users of the module */
typedef struct hheader {
	queue_t** table;    // an array of queues
	uint32_t n;          // size of array
}hheader_t;


/* 
 * SuperFastHash() -- produces a number between 0 and the tablesize-1.
 * 
 * The following (rather complicated) code, has been taken from Paul
 * Hsieh's website under the terms of the BSD license. It's a hash
 * function used all over the place nowadays, including Google Sparse
 * Hash.
 */
static uint32_t SuperFastHash (const char *data,int len,uint32_t tablesize) {
  uint32_t hash = len, tmp;
  int rem;
  
  if (len <= 0 || data == NULL)
		return 0;
  rem = len & 3;
  len >>= 2;
  /* Main loop */
  for (;len > 0; len--) {
    hash  += get16bits (data);
    tmp    = (get16bits (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }
  /* Handle end cases */
  switch (rem) {
  case 3: hash += get16bits (data);
    hash ^= hash << 16;
    hash ^= data[sizeof (uint16_t)] << 18;
    hash += hash >> 11;
    break;
  case 2: hash += get16bits (data);
    hash ^= hash << 11;
    hash += hash >> 17;
    break;
  case 1: hash += *data;
    hash ^= hash << 10;
    hash += hash >> 1;
  }
  /* Force "avalanching" of final 127 bits */
  hash ^= hash << 3;
  hash += hash >> 5;
  hash ^= hash << 4;
  hash += hash >> 17;
  hash ^= hash << 25;
  hash += hash >> 6;
  return hash % tablesize;
}


/* hopen -- opens a hash table with initial size hsize */
hashtable_t *hopen(uint32_t hsize) {
	hheader_t *hp;
	queue_t *q;   // temporary, only used in sizeof() to malloc array
	uint32_t i;

	if (hsize<1) {
		fprintf(stderr,"Error. Cannot make hash table with size < 1.\n");
		return NULL;
	}
	if ( (hp = (hheader_t*)malloc(sizeof(hheader_t))) == NULL )
		return NULL;
	q = qopen();
	if (q == NULL)
		return NULL;
	if ( (hp->table = (queue_t**)malloc(sizeof(q) * hsize)) == NULL ) {
		free(hp);
		free(q);
		return NULL;
	}
	free(q);
	hp->n = hsize;

	/* initialize each pointer in hash table with empty queue_t */
	for ( i=0; i<hp->n; i++ ) {
		(hp->table)[i] = qopen();
	}
	
	return (hashtable_t*)hp;
}


/* hclose -- closes a hash table */
void hclose(hashtable_t *htp) {
	hheader_t *hp;
	uint32_t i;
	
	if (htp != NULL) {
		hp = (hheader_t*)htp;
		
		for ( i=0; i<hp->n; i++ ) {  // for all slots in table
			qclose((hp->table)[i]);    // close queue
		}
		free(hp);  //free header
	}
}


/* hput -- puts an entry into a hash table under designated key 
 * returns 0 for success; non-zero otherwise
 */
int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen) {
	hheader_t *hp;
	uint32_t slot;

	// check that all pointers are defined
	if (htp == NULL || ep == NULL || key == NULL)
		return 1;
	if (keylen < 1) {
		fprintf(stderr,"Error. Key must have length > 0.\n");
		return 1;
	}

	hp = (hheader_t*)htp;

	slot = SuperFastHash(key, keylen, hp->n);  // use hash function

	// add element to corresponding queue
	if ( qput((hp->table)[slot], ep) != 0) {
		fprintf(stderr,"Error. Failed to add data to queue in hash table.\n");
		return 1;
	}
	return 0;
}


/* happly -- applies a function to every entry in hash table */
void happly(hashtable_t *htp, void (*fn)(void* ep)) {
	hheader_t *hp;
	uint32_t i;

	if ( htp != NULL && fn != NULL ) {
		hp = (hheader_t*)htp;

		for ( i=0; i<hp->n; i++ ) {     // for each queue in table
			qapply((hp->table)[i], fn);   // apply function to every element in queue
		}
	}
}


/* hsearch -- searchs for an entry under a designated key using a
 * designated search fn -- returns a pointer to the entry or NULL if
 * not found
 */
void *hsearch(hashtable_t *htp, 
							bool (*searchfn)(void* elementp, const void* searchkeyp), 
							const char *key, int32_t keylen) {
	hheader_t *hp;
	uint32_t slot;

	if ( htp == NULL || searchfn == NULL || key == NULL )
		return NULL;
	if ( keylen < 1 )
		return NULL;
	
	hp = (hheader_t*)htp;
	slot = SuperFastHash(key, keylen, hp->n);  // get slot based on key
	
	return qsearch((hp->table)[slot], searchfn, key);  // qsearch returns element
}


/* hremove -- removes and returns an entry under a designated key
 * using a designated search fn -- returns a pointer to the entry or
 * NULL if not found
 */
void *hremove(hashtable_t *htp, 
							bool (*searchfn)(void* elementp, const void* searchkeyp), 
							const char *key, int32_t keylen) {
	hheader_t *hp;
	uint32_t slot;

	if ( htp == NULL || searchfn == NULL || key == NULL )
		return NULL;
	if ( keylen < 1 )
		return NULL;
	
	hp = (hheader_t*)htp;
	slot = SuperFastHash(key, keylen, hp->n);  // get slot based on key
	
	return qremove((hp->table)[slot], searchfn, key);  // qsearch returns element
}
