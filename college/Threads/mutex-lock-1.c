
//seee try_lock


/*
Passing argument to the child thread
But as convention have to pass the arg by address
So here value of counter is changing so will misbehaviour occours 
Because we have no control when or which order thread will get excess the shared variale[same time more than 1 thread will excess]

Can be remove this behavior by mutex lock : 
mutex lock ensures only one thred will excess the shared variable, no control on when or in which order[same time more than 1 thread will excess]!!
see next example
*/


//https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/


/* A Slightly Less Simple PThreads Example */

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5



void *threadFunc(void *pArg) { /* thread main */
        printf("Thread number start :%d\n",*((int*)pArg));
	*((int*)pArg)=*((int*)pArg)+1;
	printf("Thread number end   :%d\n",*((int*)pArg));
	*((int*)pArg)=*((int*)pArg)+1;
	return 0;
}

int main(void) {
	int i;
	pthread_t tid[NUM_THREADS];
        
	int counter=0;
	for(i = 0; i < NUM_THREADS; i++) { /* create/fork threads */
		pthread_create(&tid[i], NULL, threadFunc, &counter);
	}
	
	for(i = 0; i < NUM_THREADS; i++) { /* wait/join threads */
		pthread_join(tid[i], NULL);
	}
       
	return 0;
}
