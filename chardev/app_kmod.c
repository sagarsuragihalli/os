#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	fd=open("/dev/myChar",O_RDWR);
	if (fd<0)
		perror("unable to  open device");
	else 
		printf("file opened successfully %d\n",fd);
	close(fd);
	return 0;
}

