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
    int val;

    fd = shm_open("/sh_mem", O_RDWR | O_CREAT, 0666);
    sem = sem_open("/cnt_sem", O_CREAT, 0666, 3);
    ftruncate(fd, 4096);
    ptr = mmap(NULL, 4096, PROT_WRITE, MAP_SHARED, fd, 0);

    buf1 = (char *)malloc(128);
    sem_wait(sem);
	sem_getvalue(sem, &val);
	printf("semaphore value : %d\n", val);
    printf("Enter msg : ");
    gets(buf1);
    sprintf(ptr, "%s", buf1);
    sleep(20);
    sem_post(sem);
    sem_close(sem);
}

