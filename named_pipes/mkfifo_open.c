#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(void) 
{
	if ( mkfifo ( "FIFO" , 0777 ) ) return 1 ;
		perror("status");
	int fd = -1 ;
	int index = 0;
	fd = open ( "FIFO" , O_WRONLY| O_NONBLOCK );
	perror("status");
	getchar();
	while (1) {
		puts("hello");
		write ( fd , 'X' , 1 ) ; 
		perror("");
		printf("%d\n" , index++);
		}
	perror("");
	return 0 ;
}
