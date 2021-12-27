//with mutexlock this will work
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<math.h>


const int N = 200000 ;
int thread1_exicution_count=0;
int thread2_exicution_count=0;
pthread_mutex_t lock; 
void *Func1(void * n )
{
  
  
   while(*((int*)n)  < N)
   {  pthread_mutex_lock(&lock); thread1_exicution_count++;
     *((int*)n)= *((int*)n) + 1; 
   pthread_mutex_unlock(&lock); 
	}
   
}
 
void *Func2(void * n )
{ 
  
  while(*((int*)n)  < N)
   {   pthread_mutex_lock(&lock); thread2_exicution_count++;
     *((int*)n)= *((int*)n) + 2; 
   pthread_mutex_unlock(&lock); 
}
}
 
int main(int argc,char **argv)
{
   pthread_mutex_init(&lock, NULL);
   pthread_t thread1_id,thread2_id;
   int n=0;
   pthread_create(&thread1_id,NULL,Func1,&n);
   pthread_create(&thread2_id,NULL,Func2,&n);
 
   pthread_join(thread1_id,NULL);
   pthread_join(thread2_id,NULL);
   

   printf("Thread1_exicution_count:%d\nThread2_exicution_count:%d\nFinal n:%d\n",thread1_exicution_count,thread2_exicution_count,n); 
    pthread_mutex_destroy(&lock); 
   
 
   return 0; 
}

/*//with mutexlock this will work
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<math.h>


const int N = 200 ;
int thread1_exicution_count=0;
int thread2_exicution_count=0;

void *Func1(int * n )
{
  while(1)
  {
   if(*n < N)
   { thread1_exicution_count++;
	printf("1:%d\n",thread1_exicution_count);
     *n= *n + 1; }
  }
  

}
 
void *Func2(int * n )
{
  while(1)
  {
   if(*n  < N)
   { thread2_exicution_count++;
     printf("2:%d\n",thread2_exicution_count);
     *n= *n + 2; }
  }

}
 
int main(int argc,char **argv)
{
   pthread_t thread1_id,thread2_id;
   int n=0;
   pthread_create(&thread1_id,NULL,Func1,&n);
   pthread_create(&thread2_id,NULL,Func2,&n);
 
   pthread_join(thread1_id,NULL);
   pthread_join(thread2_id,NULL);
   

   printf("Thread1_exicution_count:%d\nThread2_exicution_count:%d\nFinal n:%d\n",thread1_exicution_count,thread2_exicution_count,n); 
 
   
 
   return 0; 
}
*/

/*
//with mutexlock this will work
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<math.h>


const int N = 20000 ;
int thread1_exicution_count=0;
int thread2_exicution_count=0;

void *Func1(void * n )
{

   while(*((int*)n)  < N)
   { thread1_exicution_count++;
     *((int*)n)= *((int*)n) + 1; }
   
}
 
void *Func2(void * n )
{
  while(*((int*)n)  < N)
   { thread2_exicution_count++;
     *((int*)n)= *((int*)n) + 2; }

}
 
int main(int argc,char **argv)
{
   pthread_t thread1_id,thread2_id;
   int n=0;
   pthread_create(&thread1_id,NULL,Func1,&n);
   pthread_create(&thread2_id,NULL,Func2,&n);
 
   pthread_join(thread1_id,NULL);
   pthread_join(thread2_id,NULL);
   

   printf("Thread1_exicution_count:%d\nThread2_exicution_count:%d\nFinal n:%d\n",thread1_exicution_count,thread2_exicution_count,n); 
 
   
 
   return 0; 
}
*/


/*
//without mutexlock this will missbehave
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<math.h>


const int N = 20000 ;
int thread1_exicution_count=0;
int thread2_exicution_count=0;

void *Func1(void * n )
{
   int num=*((int*)n);
   while(num  < N)
   { thread1_exicution_count++;
     *((int*)n)=num+1;num++; }
   
}
 
void *Func2(void * n )
{
   int num=*((int*)n);
   while(num  < N)
   { thread2_exicution_count++;
   *((int*)n)=num+2;num+=2;  }

}
 
int main(int argc,char **argv)
{
   pthread_t thread1_id,thread2_id;
   int n=0;
   pthread_create(&thread1_id,NULL,Func1,&n);
   pthread_create(&thread2_id,NULL,Func2,&n);
 
   pthread_join(thread1_id,NULL);
   pthread_join(thread2_id,NULL);
   

   printf("Thread1_exicution_count:%d\nThread2_exicution_count:%d\nFinal n:%d\n",thread1_exicution_count,thread2_exicution_count,n); 
 
   
 
   return 0; 
}*/
 
