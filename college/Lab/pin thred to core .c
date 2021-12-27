/**
 * pin threads to given core
 */


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<errno.h>
#include<sys/time.h>
#define handle_error_en(en, msg) \
               do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)
int n;
void *myThreadFun1(void *s1_void_ptr);
void *myThreadFun2(void *s2_void_ptr);
 




int main()
{
    int i,j,sum1=0,sum2=0,s,t;
   
    scanf("%d",&n);
   
    pthread_t thread_id1, thread_id2;
    cpu_set_t cpuset;
   
    struct timeval start ,end;
    gettimeofday(&start,NULL);

    printf("Before Thread\n");
    pthread_create(&thread_id1, NULL, myThreadFun1,&sum1);
    printf("Thread1 created\n");
    printf("thread1 id is %ld\n",thread_id1);
   
   

    pthread_create(&thread_id2, NULL, myThreadFun2, &sum2);
    printf("Thread2 created\n");
    printf("thread2 id is %ld\n",thread_id2);
   
    CPU_ZERO(&cpuset);
    for (j = 0; j < 8; j++)
               CPU_SET(j, &cpuset);

    s = pthread_setaffinity_np(thread_id1, sizeof(cpu_set_t), &cpuset);
    t= pthread_setaffinity_np(thread_id2, sizeof(cpu_set_t), &cpuset);
           if (s != 0 )
               handle_error_en(s, "pthread_setaffinity_np");
            if (t!= 0 )
               handle_error_en(t, "pthread_setaffinity_np");


           /* Check the actual affinity mask assigned to the thread */

           s = pthread_getaffinity_np(thread_id1, sizeof(cpu_set_t), &cpuset);
           t = pthread_getaffinity_np(thread_id2, sizeof(cpu_set_t), &cpuset);
           if (s != 0)
               handle_error_en(s, "pthread_getaffinity_np");
            if (t != 0)
               handle_error_en(t, "pthread_getaffinity_np");
               
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    printf("After Thread2\n");

    printf("%d",sum1+sum2);
    printf("\n");
   
    printf("Set returned by pthread_getaffinity_np() contained:\n");
    for (j = 0; j < CPU_SETSIZE; j++)
               if (CPU_ISSET(j, &cpuset))
                   printf("    CPU %d\n", j);

    gettimeofday(&end,NULL);
    long seconds = (end.tv_sec - start.tv_sec);
    long micros= ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    printf("\ntime taken-> %d\n",micros);
    exit(0);
}

void *myThreadFun1(void *s1_void_ptr)
{
    int i, *s1_ptr = (int *)s1_void_ptr;
   
    for(i=1;i<=n;i=i+2)
    {
         printf("%d\t",i);
         *s1_ptr=*s1_ptr+i;
       
     }  
       
    //printf("end of thread 1 \n");
   
    printf("\n");
    printf("odd numbers printed. Thread1 over\n");
   
    return NULL;
}

void *myThreadFun2(void *s2_void_ptr)
{
    int i, *s2_ptr = (int *)s2_void_ptr;
   
    for(i=0;i<=n;i=i+2)
    {
         printf("%d\t",i);
         *s2_ptr=*s2_ptr+i;
       
     }  
       
    //printf("end of thread 1 \n");
   
    printf("\n");
    printf("even numbers printed. Thread1 over\n");
    return NULL;
} 
