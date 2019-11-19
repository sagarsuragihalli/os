#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int x=10;

int main()
{
	pid_t child;
	child = fork();
	if(child < 0) {
		perror("Fork Failed");
		return 1;
	}
	else if(child>0){		
		x=x-3;
		printf("parent %d\n",x);
		printf("parent:ppid = %d, pid = %d, cid = %d\n",getppid(), getpid,child);
	}
	else {
		x++;
		printf("child %d\n",x);
		printf("child:ppid = %d, pid = %d, cid = %d\n",getppid(), getpid,child);
	}
}
