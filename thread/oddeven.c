#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

//int i=0;
unsigned int shared_data = 0;
int arr[100];
void* PrintEvenNos(void*);
void* PrintOddNos(void*);

void main(void)
{
pthread_t tid[2];
    pthread_create(&tid[0],0,&PrintEvenNos,0);
    pthread_create(&tid[1],0,&PrintOddNos,0);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
}

void* PrintEvenNos(void *ptr)
{
//int i=0;
for(;shared_data<=100;)
{
	if(shared_data%2 == 0)
         {
             printf("Even:%d\t",shared_data);
             shared_data++;
             
         }
}
}
/*     do
     {
         if(shared_data%2 == 0)
         {
             printf("Even:%d\n",shared_data);
             shared_data++;
	     
         }
     } while (shared_data <= 100);*/


void* PrintOddNos(void* ptr1)
{
for(;shared_data<=100;)
{
        if(shared_data%2 != 0)
         {
             printf("odd:%d\t",shared_data);
             shared_data++;

         }
}
}
/*
//int i=1;
    do
    {
        if(shared_data%2 != 0)
        {
            printf("odd:%d\n",shared_data);
            shared_data++;
        }
    } while (shared_data<= 100);
}*/
