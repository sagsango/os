/*

Thread creation
then join the thread from parent : insure child get exicuted then parent will get exit
Take care of it's child thread

or

Thread creation
No join of parent to child thread
two of them will be indipendent
here in the program main may* get exicuted complitly first then after child will get exit(0)

*/


/* PThread Creation */ 

#include <stdio.h>
#include <pthread.h>

void *foo (void *arg) {		/* thread main */
	printf("Foobar!\n");
	pthread_exit(NULL);
}

int main (void) {

	int i;
	pthread_t tid;
	
	pthread_attr_t attr;
	pthread_attr_init(&attr); // Required!!!
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	pthread_create(&tid, &attr, foo, NULL);

	return 0;
}


