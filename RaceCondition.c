#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
//#include<sys/shm.h>

static var=0;

void *f1()
{
	int x=var;
	x++;
	sleep(1);
	var=x;
}
void *f2()
{
	int x=var;
	x--;
	sleep(1);
	var=x;
}

void main()
{
	pthread_t p1,p2;
	
	pthread_create(&p1,NULL,f1,NULL);
	pthread_create(&p2,NULL,f2,NULL);
	
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	
	printf("%d\n",var);
}
