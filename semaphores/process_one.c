#include<stdio.h>
#include<semaphore.h>
#include<sys/stat.h>
#include<fcntl.h>

int main ( void ) 
{
	sem_t *sem = NULL ;
	sem = sem_open ("/sem" ,O_CREAT | O_RDWR , 0644 , 1 ) ;
	if ( !sem ) { perror("creation"); return 1 ; } 
	sem_wait ( sem ) ;
	printf("semaphore aquired");
	getchar() ;
	sem_post(sem) ;

	return 0 ;

}
