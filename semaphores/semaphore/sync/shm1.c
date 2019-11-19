#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
	int fd;
	void *ptr;
	char *buf;
	int p = 1;
	int i;
	sem_t *sem;
	sem_unlink("/sem_syn");	
	sem = sem_open("/sem_syn", O_CREAT, 0666, 1);
	fd = shm_open("/shm_mem", O_RDWR | O_CREAT, 0666);
	ftruncate(fd, 4096);
	sem_wait(sem);
	ptr = mmap(NULL, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	
	buf = (char *)malloc(sizeof(char));
//	for(i = 0; i < 100; i++)
	{
//		gets(buf);
	//	sem_wait
		sprintf(ptr, "%d", p);
//		printf("%d\n", p);
	}
//	getchar();
//	ptr++;
	sprintf(ptr, "%s", "r");
	sem_post(sem);
	sem_close(sem);
	close(fd);
}
