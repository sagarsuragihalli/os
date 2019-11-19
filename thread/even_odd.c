#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>



void* even(void* arg)
{
static	int i = 0;
	printf("\ninside even\n");
	for(i=0;i<=100;i++)
	{
		if(i%2 == 0){
			printf("%d ",i);
			sleep(.5);
		}

	}
	printf("\n");	
}



int main()
{

	pthread_t ID;
	int status;

	static int i =1;
	printf("Inside main()\n");
	for(i = 1; i<=100; i++)
	{
		if(i%2){
			printf("%d ",i);
			sleep(.5);
		}
	}
	
	status = pthread_create(&ID,NULL,&even,NULL);

	if(status != 0 ){
		perror("failed to create thread\n");
		exit(1);
	}

	pthread_join(ID,NULL);
	
	return 0;
}
		

	

