/**
 * C program to create 2 thread 
 * 1st thread will find the sum of odd intigers from 1 to n
 * 2nd thread will find the sum of the even integers from 1 to n
 * so total time of the process will be less
 * because thread will exicute in parallal
 **/

#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<math.h>

void *evenFunc(void * n )
{
   int sum=0,i;
   for(i=2;i<=*((int*)n);i+=2)
   {
      printf("Hey I'm even:%d\n",i);
      sum+=i;
   }
   return (void*)sum;
}

void *oddFunc(void * n )
{
  int sum=0,i;
  for(i=1;i<=*((int*)n);i+=2)
  {
    printf("Hey I'm odd:%d\n",i);
    sum+=i;
  }
  return (void*)sum;
}

int main(int argc,char **argv)
{
   int n=1000;
   pthread_t thread1_id,thread2_id;
   void *eve_sum;
   void *odd_sum;
   pthread_create(&thread1_id,NULL,evenFunc,&n);
   pthread_create(&thread2_id,NULL,oddFunc,&n);
    
   pthread_join(thread1_id,&eve_sum );
   pthread_join(thread2_id,&odd_sum); 

   printf("Even Sum:%d\nOdd Sum:%d\n",(int)eve_sum,(int)odd_sum);

   return 0; 
}


/**
 * Comapring the time taken by programs
 * But not getting satifacotry results
 **/

/*****************************************************************************************************************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<math.h>
#include<time.h>
#define int long long
void *evenFunc(void * n )
{
   int sum=0,i;
   for(i=2;i<=*((int*)n);i+=2)
   {
      //printf("Hey I'm even:%d\n",i);
      sum+=i;
   }
   return (void*)sum;
}

void *oddFunc(void * n )
{
  int sum=0,i;
  for(i=1;i<=*((int*)n);i+=2)
  {
    //printf("Hey I'm odd:%d\n",i);
    sum+=i;
  }
  return (void*)sum;
}

int32_t main(int argc,char **argv)
{
   time_t start_time,end_time,mid_time1,mid_time2;
   //Compilation start from here
   
   int n=1000000;
   pthread_t thread1_id,thread2_id;
   void *eve_sum;
   void *odd_sum;
   start_time=clock();
   pthread_create(&thread1_id,NULL,evenFunc,&n);
   mid_time1=clock();
   pthread_create(&thread2_id,NULL,oddFunc,&n);
    mid_time2=clock();
    
   pthread_join(thread1_id,&eve_sum );
   pthread_join(thread2_id,&odd_sum); 

   //printf("Even Sum:%d\nOdd Sum:%d\n",(int)eve_sum,(int)odd_sum);
   //Compilation end here
   end_time=clock();
   
   printf("Time Taken by the program:%lld,%lld,%lld\n",mid_time1-start_time,mid_time2-mid_time1,end_time-start_time);

   return 0; 
}*/


/**************************************************************************************************************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<math.h>
#include<time.h>
#define int long long

int odd_sum_func(int n)
{
    int sum=0,i;
    for(i=1;i<=((int)n);i+=2)
    {
       //printf("Hey I'm odd:%d\n",i);
       sum+=i;
    }
    return sum;
}

int even_sum_func(int n)
{
   int sum=0,i;
   for(i=2;i<=((int)n);i+=2)
   {
       //printf("Hey I'm even:%d\n",i);
       sum+=i;
   }
   return sum;
}
   
int main()
{
   time_t start_time,end_time;
   //Compilation start from here
   start_time=clock();
   int n=1000000;
   int eve_sum=even_sum_func(n);
   int odd_sum=odd_sum_func(n);
   
   // printf("Even Sum:%d\nOdd Sum:%d\n",(int)eve_sum,(int)odd_sum);
    //Compilation end here
    end_time=clock();

    printf("Time Taken by the program:%lld",end_time-start_time);
}*/

/**************************************************************************************************************************/

/*
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<math.h>
#include<time.h>

int main()
{
   time_t start_time,end_time;
   //Compilation start from here
   start_time=clock();

   int n=1000;
   int eve_sum=0;
   int odd_sum=0;
   
   int i;
   for(i=1;i<=((int)n);i+=2)
   {
       printf("Hey I'm odd:%d\n",i);
       odd_sum+=i;
   }
   for(i=2;i<=((int)n);i+=2)
   {
       printf("Hey I'm even:%d\n",i);
       eve_sum+=i;
   }
   printf("Even Sum:%d\nOdd Sum:%d\n",(int)eve_sum,(int)odd_sum);

   //Compilation end here
    end_time=clock();
   printf("Time Taken by the program:%d\n",end_time-start_time);
}*/


/******************************************************************************************************************************/



