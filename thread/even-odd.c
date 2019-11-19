#include<stdio.h>
#include<pthread.h>

pthread_t tid[2];
unsigned int shared_data = 0;
pthread_mutex_t mutex;
unsigned int rc;

void* PrintEvenNos(void*);
//void* PrintOddNos(void*);

void main(void)
{
    pthread_create(&tid[0],0,&PrintEvenNos,0);
    pthread_create(&tid[1],0,&PrintEvenNos,0);
//    pthread_create(&tid[1],0,&PrintOddNos,0);

    while(1);
	//pthread_join(tid[0],NULL);
  //  pthread_join(tid[1],NULL);
}

void* PrintEvenNos(void *ptr)
{
     do
     {
         if(shared_data%2 == 0)
         {
     rc = pthread_mutex_lock(&mutex);
             printf("Even:%d\n", shared_data);
             shared_data++;
             rc=pthread_mutex_unlock(&mutex);
         }
         else
         {
    rc = pthread_mutex_lock(&mutex);
            printf("odd:%d\n", shared_data);
            shared_data++;
            rc = pthread_mutex_unlock(&mutex);
         }
     } while (shared_data <= 25000);
}

/*void* PrintOddNos(void* ptr1)
{
    do
    {
        if(shared_data%2 != 0)
        {
        }
        else
        {
        }
    } while (shared_data <= 5000);
}*/
