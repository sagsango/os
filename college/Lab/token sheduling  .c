/**
 * Process sheduling : round robin
 **/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int min(int a,int b)
{ 
   return a < b ? a : b ;
}	

int main()
{
    int process_count=4;
    int process_rem=process_count;
    int total_token=20;
    

    int time_req[process_count];
    int time_used[]={0,0,0,0};


    time_req[0]=4;
    time_req[1]=5;
    time_req[2]=10;
    time_req[3]=9;
   
    int tq=3;
	int t=0;
    
    int process_id[total_token];
    int i;
    for(i=0;i<total_token;i++)
    process_id[i]=i%process_count;

    int process_end[]={0,0,0,0};

    while( process_rem )
    {
        int token=rand()%total_token;
        int process=process_id[token];
        printf("Token Generated:%d and process:%d\n",token,process);
         
        if( time_used[ process ] < time_req[ process ])
        { 
            int start=t;
 			int run_time=min(time_req[process]-time_used[process] , tq );
            t+=run_time;
  			time_used[process]+=run_time;
            int end=t;
            printf("Run Time of %d is from %d to %d\n",process,start,end);

           if(time_req[process]==time_used[process])
           {
                process_rem-=1;
           }
              
        }
     }
}
   
