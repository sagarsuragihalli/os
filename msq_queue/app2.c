#include <stdio.h>
#include <unistd.h>
#include <mqueue.h>
#include <stdlib.h>
#include <string.h>

#define MSG_NAME "/mg_q"
#define PERMISSION 0777
#define MAXI_MSG 10
#define MAXI_MES_SIZE 8192

#define BUF_SIZE 128 + MAXI_MES_SIZE


int main(int argc , char **argv)
{
	mqd_t m1;
	char mseg1[BUF_SIZE];
	char mseg2[BUF_SIZE];

	struct mq_attr  attr;


	attr.mq_flags = 0;
	attr.mq_maxmsg = MAXI_MSG;
	attr.mq_msgsize = MAXI_MES_SIZE;
	attr.mq_curmsgs = 0;
	
		m1 = mq_open ( MSG_NAME, O_CREAT | O_RDWR, PERMISSION, &attr);
		
		if (m1 < -1 ) {
			perror (" Oops Mesg failed !");
			exit (-1);
		}
		
	while ( 1 ) {
		printf ("User 1 : ");

		if (fgets(mseg1, BUF_SIZE, stdin) == NULL){
			perror (" Oops fgtes failed !");
			exit (-1);
		} 

		if (mq_send (m1, mseg1, strlen(mseg1) + 1, 0) == -1){
			perror (" Oops mq_Send failed !");
			exit (-1);
		}
	
			 
		if (mq_receive (m1, mseg2, BUF_SIZE, NULL) == -1) {
			perror (" Oops mq_recive failed ! ");
			exit (-1);
		}	
		
		printf ("User 2: %s\n", mseg2 );

	}

	if ( mq_close (m1) == -1)
			exit(-1);
	
	if ( mq_unlink (m1) == -1)
			exit (-1);
	
	return 0;

}
		
