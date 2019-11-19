#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t sem; 
int a = 0;
  
void* thread1(void* arg) 
{ 
//	while(a < 10)
//	{
    //wait 
    sem_wait(&sem); 
    printf("\nEntered..\n"); 
  
    //critical section 
	a++;
    //sleep(4); 
      
    //signal 
    printf("\nJust Exiting...\n"); 
    sem_post(&sem); 
//	}
} 

void* thread2(void* arg)
{
    //wait 
    sem_wait(&sem);
    printf("\nEntered..\n");

	printf("%d = %s\n", a, (a % 2 == 0) ? "Even" : "Odd");
    //critical section 
    //sleep(4);

    //signal 
    printf("\nJust Exiting...\n");
    sem_post(&sem); 
}
   
int main() 
{ 
    sem_init(&sem, 0, 1); 
    pthread_t t1,t2; 
    pthread_create(&t1,NULL,thread1,NULL); 
    sleep(2); 
    pthread_create(&t2,NULL,thread2,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
    sem_destroy(&sem); 
    return 0; 
} 
