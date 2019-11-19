#include<stdio.h>
#include<semaphore.h>
#include<sys/stat.h>
#include<fcntl.h>

int main ( void ) 
{
	sem_t *sem = NULL ;
	sem = sem_open ("/sem" ,O_RDWR ) ;
	if ( !sem ) { 
		perror("opening"); 
		return 1 ; 
	} 
	sem_wait ( sem ) ;
	printf("semaphore aquired");
	getchar() ;
	sem_post(sem) ;
	sem_close(sem);
	sem_unlink("/sem");

	return 0 ;

}
