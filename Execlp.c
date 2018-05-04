#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
//#include<sys/shm.h>

void main()
{
	pid_t p=fork();
	
	if(p==-1)
	printf("Fork Failed...");
	else if(p==0)
	{
		execlp("/bin/ps","ps",NULL);
		printf("Hello");
	}
}
