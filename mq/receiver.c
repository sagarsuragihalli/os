#include <stdio.h>
#include <unistd.h>
#include <mqueue.h>
#include <stdlib.h>
#include <string.h>


#define MSG_NAME "/my_q"
#define PERMISSION 0777
#define MAX_MSG 10
#define MAX_MES_SIZE 8193

#define BUF_SIZE 128 + MAX_MES_SIZE


int main(int argc , char **argv)
{
	mqd_t m1, m2;
	char mseg2[BUF_SIZE];

	struct mq_attr  attr;


	attr.mq_flags = 0;
	attr.mq_maxmsg = MAX_MSG;
	attr.mq_msgsize = MAX_MES_SIZE;
	attr.mq_curmsgs = 0;

	m1 = mq_open ( MSG_NAME,  O_RDWR );
		
		if (m1 < 0 ) {
			perror (" Oops Mesg failed !");
			exit (-1);
		}

	while ( 1 ) {
			 
		if (mq_receive (m1, mseg2, BUF_SIZE, NULL) == -1) {
			perror (" Oops mq_recive failed ! ");
			exit (-1);
		}	
		
		printf ("Message in Queue: %s\n", mseg2 );
	}

	if ( mq_close (m1) == -1)
			exit(-1);
	
//	if ( mq_unlink (m1) == -1)
//			exit (-1);
	
	return 0;

}
		
