#include	<stdio.h>

int main  ( void ) 
{
	FILE *fp = NULL ;
	
	FILE *fp2 = NULL ;

	char ch = 0 ;

	fp = popen ( "grep open" , "w" ) ;
	
	fp2 = popen ( "ls" , "r" ) ;

	if ( !fp ) return 1 ;

	//printf("%p %p\n" , stderr , fp -> _chain );
	
	while ( ( ch = fgetc(fp2) ) != EOF )
	fprintf(fp , "%c" ,ch );

	//while ( ( ch = fgetc(fp) ) != EOF ) printf ("%c" , ch) ;

	puts("") ;

	fclose(fp) ;

	return 0 ;

}
