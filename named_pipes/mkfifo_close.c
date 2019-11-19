#include<sys/types.h>
#include<sys/stat.h>
int main(void) 
{
	if ( system ( "rm somefifo" ) ) return 1 ;
	return 0 ;
}
