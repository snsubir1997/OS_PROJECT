#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
//#include<sys/shm.h>

static var=0;
pthread_mutex_t l;
void *f1()
{
	pthread_mutex_lock(&l);
	int x=var;
	x++;
	sleep(1);
	var=x;
	pthread_mutex_unlock(&l);
}
void *f2()
{
	pthread_mutex_lock(&l);
	int x=var;
	x--;
	sleep(1);
	var=x;
	pthread_mutex_unlock(&l);
}

void main()
{
	pthread_t p1,p2;
	
	pthread_mutex_init(&l,NULL);
	
	pthread_create(&p1,NULL,f1,NULL);
	pthread_create(&p2,NULL,f2,NULL);
	
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	
	printf("%d\n",var);
}
