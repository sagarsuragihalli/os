#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main(void)
{
    int fd;
    void *ptr;
    char *buf;
	sem_t *sem;
	int *val;

    sem = sem_open("/sem_syn", O_EXCL);
	fd = shm_open("/shm_mem", O_RDWR | O_CREAT, 0666);
    ftruncate(fd, 4096);
	
	sem_getvalue(sem, val);
//	if(sem_wait(sem))
//	{
//		perror("error");
//	}
	
	printf("value of semaphore : %d\n", *val);

	//sem_wait(sem);
    ptr = mmap(NULL, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

    buf = (char *)malloc(sizeof(char));
	memcpy(buf, ptr, 128);
    //gets(buf);
    printf("%s", buf);
    close(fd);
}
