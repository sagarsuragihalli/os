#include	<stdio.h>

int main ( void ) 
{
	FILE *fp = NULL ;

	fp = fdopen ( 0 , "r" ) ;

	if ( !fp ) return 1 ;

	printf("%p %p \n" ,fp , stdin);

	fclose (fp) ;

	return 0 ;

}
