#include	<stdio.h>

int main  ( void ) 
{
	FILE *fp = NULL ;

	char ch = 0 ;

	fp = popen ( "git" , "r" ) ;

	if ( !fp ) return 1 ;

	//printf("%p %p\n" , stderr , fp -> _chain );

	while ( ( ch = fgetc(fp) ) != EOF ) printf ("%c" , ch) ;

	puts("") ;

	fclose(fp) ;

	return 0 ;

}
