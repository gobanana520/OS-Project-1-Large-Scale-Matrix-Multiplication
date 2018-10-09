#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

const int UPPER = 1000; /* # times counter is incremented by each thread */

int counter = 0;        // variable to be incremented by each thread 
sem_t semaphore;        // global semaphore, used for mutual exclusion
pthread_t tid[10];      // array of thread identifiers


void *
increment( void *arg )
{
	/* Parameter passed is the thread number.  Since the parameter could be 
	 anything, it is passed as void * and must be "converted". */
	/* following are local variables of the thread; other threads can't acccess these variables */
	int i,j,temp;
	int id = (int) arg;
	int spin; /* to slow down threads */

	printf("Thread %d is startng\n",id);

	// Simply iterate UPPER times, incrementing the counter each iteration.
	// Since the variable counter is a shared/global variable, protect
	// the modification of the variable by a semaphore.

	for(j = 0; j < UPPER; j++ )
	{
		spin=0;
		for (i=0;i<1000000;i++) spin++;
		sem_wait( &semaphore ); // semaphore WAIT operation
		 counter++;
		sem_post( &semaphore ); // semaphore SIGNAL operation
	}

	printf("Thread %d is ending\n",id); 
	return NULL;
}


int 
main()
{
	int i, no_threads;
	no_threads=6;


	sem_init( &semaphore, 0, 1 );


	for( i = 0; i < no_threads; i++ ) 
		pthread_create( &tid[ i ], NULL, increment, (void *) i );


	for( i = 0; i < no_threads; i++ ) 
		pthread_join( tid[ i ], NULL );

	printf("Final value of counter is %d and this should be %d\n",counter,no_threads*UPPER);

	return 0;
}