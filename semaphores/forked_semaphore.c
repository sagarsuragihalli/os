#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>

sem_t sem;
sem_t sem1;

int main(void)
{
    sem_init(&sem, 1, 1);
    sem_init(&sem1, 1, 0);
	pid_t x = fork();
	perror(""); 
    if (x) {
        while (1) {
            sem_wait(&sem);
            printf("other\n");
            sem_post(&sem1);
        }
    }

    else {
        while (1) {
            sem_wait(&sem1);
            printf("anther\n");
            sem_post(&sem);
        }
    }

    return 0;
}
