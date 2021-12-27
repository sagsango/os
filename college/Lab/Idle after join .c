#include<stdio.h>    
#include<stdlib.h>    
#include<pthread.h>
#include<time.h>

//using namespace std;

#define NUM_THREADS 100

struct thread_data
{
  int  thread_id;
  char *message;
};

void *PrintHello(void *threadarg)
{
   struct thread_data *my_data;   

   my_data = (struct thread_data *) threadarg;

   printf( "Thread ID : %d\n", my_data->thread_id );

   printf( " Message : %s\n" , my_data->message);
    
   time_t t=time(NULL);
   while( time(NULL) < t + 1 );
   //pthread_exit(NULL);
}

int main ()
{
   pthread_t threads[NUM_THREADS];

   struct thread_data td[NUM_THREADS];

   int rc, i;


   for( i=0; i < NUM_THREADS; i++ )    
   {

      //"main() : creating thread, " << i 

      td[i].thread_id = i;

      td[i].message = "This is message";

      rc = pthread_create(&threads[i], NULL,

                          PrintHello, (void *)&td[i]);

      pthread_join(threads[i],NULL);  
   } 
   /*for( i=0; i < NUM_THREADS; i++ )    
   pthread_join(threads[i],NULL); */   
   //pthread_exit(NULL);    
}
