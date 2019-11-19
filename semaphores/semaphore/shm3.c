#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
    int fd;
    void *ptr;
    char *buf;
	int p = 2;
	int i;
	
    fd = shm_open("/shm_mem", O_RDWR | O_CREAT, 0666);
    ftruncate(fd, 4096);

    ptr = mmap(NULL, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

    buf = (char *)malloc(sizeof(char));
//    gets(buf);
//	for(i = 0; i < 100; i++)
    {
    //gets(buf);
       sprintf(ptr, "%d", p);
    }
    //sprintf(ptr, "%s", buf);
    close(fd);
}

