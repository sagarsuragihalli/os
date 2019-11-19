#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid1;
	pid_t pid2;
	pid1 = fork();
	if(pid1 < 0) {
		perror("Fork Failed");
		return 1;
	}
	pid2 = fork();
	if(pid2 < 0) {
		perror("Fork Failed");
		return 1;
	}
//	else if(pid == 0){
		printf("time=%d,pid=%d,pid1=%d,pid2=%d ,Hello World\n",__TIME__,getpid(),pid1,pid2);
//	}
	return 0;
}
