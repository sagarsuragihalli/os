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
    sem_t *sem;
    int val;

    fd = shm_open("/sh_mem", O_RDWR, 0666);
    sem = sem_open("/cnt_sem", O_EXCL);
    ftruncate(fd, 4096);
    ptr = mmap(NULL, 4096, PROT_WRITE, MAP_SHARED, fd, 0);

    buf1 = (char *)malloc(128);
	sem_getvalue(sem, &val);
    printf("semaphore value : %d\n", val);
    sem_wait(sem);
   	sleep(20);
	memcpy(buf1, ptr, 128);
    printf("Received msg : %s\n", buf1);
    sem_post(sem);
    sem_close(sem);
}
