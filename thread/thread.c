
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void *thread_func()
{
	printf("Thread Function...\n");
	printf("new thread ID = %ld\n", pthread_self());
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	int status;
	int *retval;
	
	printf("Inside main thread\n");
	printf("main thread ID = %ld\n", getpid());

	status = pthread_create(&tid, NULL, &thread_func, NULL);
	if(status != 0){
		perror("pthread failed!!!");
		exit(1);
	}
	else if(status == 0){
		
		retval = (int*)malloc(4);
		pthread_join(tid, (void **)&retval);
	}

	printf("back to main thread\n");
	
	pthread_exit(NULL);
	return 0;
}

