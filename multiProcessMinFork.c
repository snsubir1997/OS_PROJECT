#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
//#include<sys/shm.h>

void main()
{
	fork();
	printf("Hello");
	fork();
	printf("Hello");
	fork();
	printf("Hello");	
}
