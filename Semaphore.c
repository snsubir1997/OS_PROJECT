#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>
//#include<sys/shm.h>

static var=0;
sem_t l;
void *f1()
{
	sem_wait(&l);
	int x=var;
	x++;
	sleep(1);
	var=x;
	sem_post(&l);
}
void *f2()
{
	sem_wait(&l);
	int x=var;
	x--;
	sleep(1);
	var=x;
	sem_post(&l);
}

void main()
{
	pthread_t p1,p2;
	sem_init(&l,0,1);
	pthread_create(&p1,NULL,f1,NULL);
	pthread_create(&p2,NULL,f2,NULL);
	
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	
	printf("%d\n",var);
}
