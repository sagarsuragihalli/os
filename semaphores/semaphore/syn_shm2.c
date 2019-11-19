#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
    int fd;
    void *ptr;
    char *buf1;
    char *buf2;
    sem_t *sem;
	int i = 0;

    fd = shm_open("/sh_mem", O_RDWR, 0666);
    sem = sem_open("/sem1", O_EXCL);
    ftruncate(fd, 4096);
    ptr = mmap(NULL, 4096, PROT_WRITE, MAP_SHARED, fd, 0);

    buf1 = (char *)malloc(128);
    buf2 = (char *)malloc(128);
    while(i < 5)
    {
        sem_wait(sem);
        memcpy(buf2, ptr, 128);
        printf("Received msg : %s\n", buf2);
        sem_post(sem);
		sem_wait(sem);
        printf("Enter msg : ");
        gets(buf1);
        sprintf(ptr, "%s", buf1);
        sem_post(sem);
        sleep(2);
		i++;
    }
    sem_close(sem);
	sem_unlink("/sem1");
	shm_unlink("/sh_mem");
}

