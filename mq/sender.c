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
	char mseg1[BUF_SIZE];
	char buf[BUF_SIZE];
	unsigned int msg_prio;

	struct mq_attr  attr;


	attr.mq_flags = 0;
	attr.mq_maxmsg = MAX_MSG;
	attr.mq_msgsize = MAX_MES_SIZE;
	attr.mq_curmsgs = 0;

	m1 = mq_open ( MSG_NAME,  O_RDWR|O_CREAT );
		
		if (m1 < 0 ) {
			perror (" Oops Mesg failed !");
			exit (-1);
		}

	while ( 1 ) {	
		mq_getattr(m1,&attr);
		printf("Current message number: %ld\n", attr.mq_curmsgs);
		printf("Enter message: ");	
		if (fgets(mseg1, BUF_SIZE, stdin) == NULL){
			perror (" Oops fgtes failed !");
			exit (-1);
		} 
		printf("Enter priority: ");
		fgets(buf,32,stdin);
		msg_prio=atoi(buf);
		if (mq_send (m1, mseg1, strlen(mseg1) + 1, msg_prio) == -1){
			perror (" Oops mq_Send failed !");
			exit (-1);
		}		

	}

	if ( mq_close (m1) == -1)
			exit(-1);
	
//	if ( mq_unlink (m1) == -1)
//			exit (-1);
	
	return 0;

}
		
