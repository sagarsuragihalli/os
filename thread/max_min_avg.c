#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void *avg_func(void *ptr);
void *min_func(void *ptr);
void *max_func(void *ptr);

double avg;        
int min;
int max;

typedef struct datastruct
{
    int size;
    int * values;
}datastruct;

int main(int argc, char *argv[])
{
    while(argc <=1){
        printf("Incorrect input. No arguments entered.\n");
        printf("Please enter one or more inputs.\n");
        exit(0);
	}
    
    int i = 0;
    int copy[argc-1];
    for(i; i < (argc -1); i++){
        copy[i] = atoi(argv[i+1]);
    }
        
    pthread_t thread1, thread2, thread3;
    int  t1, t2, t3;
 
    printf("Running: %s\n\n", argv[0]);
    
    datastruct ds = {argc - 1, copy};

    t1 = pthread_create(&thread1, NULL, (void *) avg_func, (void *) &ds);
    if(t1){
        fprintf(stderr,"Error - pthread_create() return code: %d\n", t1);
        exit(EXIT_FAILURE);
    }
 
    t2 = pthread_create(&thread2, NULL, (void *) min_func, (void *) &ds);
    if(t2){
        fprintf(stderr,"Error - pthread_create() return code: %d\n",t2);
        exit(EXIT_FAILURE);
    }
     
    t3 = pthread_create(&thread3, NULL, (void *) max_func, (void *) &ds);
    if(t3){
        fprintf(stderr,"Error - pthread_create() return code: %d\n", t3);
        exit(EXIT_FAILURE);
    }
 
    printf("pthread_create() for Thread 1 returns: %d\n",t1);
    printf("pthread_create() for Thread 2 returns: %d\n",t2);
    printf("pthread_create() for Thread 3 returns: %d\n\n",t3);
 
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
 
    printf("The average:  %g\n", avg);
    printf("The minimum:  %d\n", min);
    printf("The maximum:  %d\n", max);
 
}
 
void *avg_func(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;
    
    int sz = copy->size;
    int i;
    
    for(i = 0; i < sz; i++)
    {
        avg += (copy->values[i]);    
    }                              
    avg = (int)(avg / sz);       
}

void *min_func(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;
    
    int sz = copy->size;
    int i;
    
    min = (copy->values[0]);
    for(i = 1; i < sz; i++)
    {
        if(min > (copy->values[i]))
        {
            min = (copy->values[i]);
        }
    }
}

void *max_func(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;
    
    int sz = copy->size;
    int i;
    
    max = copy->values[0];
    
    for(i = 1; i < sz; i++)
    {
        if(max < copy->values[i])
        {
            max = copy->values[i];
        }
    }
}
