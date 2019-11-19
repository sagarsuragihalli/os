#include	<unistd.h>

#include	<stdio.h>

#include <fcntl.h>  

#include <string.h>  

int main ( void ) 
{
		int fd[2] = {} ;

		int index = 0 ;

		char buf2[8000] ;

		char buf[20] = {} ;

			if ( pipe ( fd ) ) {

				perror ("creating a pipe");

				return 1 ;

				}

//				printf("fds by pipe %d %d \n" , fd[0] , fd[1]);
		 
/*(		if ( pipe2 ( fd  , O_NONBLOCK & 0 ) ) {

				perror ("creating a pipe2");

				return 1 ;

		}
*/		memset(buf2, '1' , sizeof buf2 ) ;

		printf("fds by pipe2 %d %d \n" , fd[0] , fd[1]);

#define readfd fd[0] 

#define writefd fd[1] 

		//		if ( fork() ) {

		//				sleep(2) ;

		//while ( 1 ) {

				printf("in while %d %d\n", index++ , write ( writefd , buf2 , sizeof buf2 ) ) ;


//				perror("write");

		//}
	getchar();

		//		}

		/*		else {

				read ( readfd , buf , sizeof ( buf ) ) ;

				perror("read");

				printf("data from pipe is %s \n" , buf );

				}*/

		return 0 ;

}
