#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
sem_t sem ;

void * read1()
{
	sem_wait ( &sem ); 
	puts("another");
	sem_post ( &sem ) ;

}
void * write1()
{
	sem_wait ( &sem ); 
	puts("other");
	sem_post ( &sem ) ;

}

int main()
{
		int status = 0 ;
		pthread_t tr, tw;
		sem_init ( &sem , 0 , 1  ) ;

		pthread_create(&tr,NULL,read1,NULL);
		pthread_create(&tw,NULL,write1,NULL);

		pthread_join(tr,NULL);
		pthread_join(tw,NULL);
		return 0;
}
