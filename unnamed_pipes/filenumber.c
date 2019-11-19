#include	<stdio.h>

int main ( void ) 
{
	printf("file no for stdin %d\n" , fileno(stdin));
	
	printf("file no for stdout %d\n" , fileno(stdout));
	
	printf("file no for stderr %d\n" , fileno(stderr));

	return  0 ;

}
