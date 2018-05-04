#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
//#include<sys/shm.h>

void main()
{
	printf("Root. I am %d.My parent is %d\n",getpid(),getppid());
	pid_t p1=fork();
	
	if(p1==-1)
	{
		printf("Error creating process\n");
	}
	else if(p1==0)
	{
		printf("P1 created. I am %d.My parent is %d\n",getpid(),getppid());
		
		pid_t p3=fork();
		if(p3==-1)
		{
			printf("Error creating process\n");
		}
		else if(p3==0)
		{
			printf("P3 created. I am %d.My parent is %d\n",getpid(),getppid());
			sleep(105);
		}
		

		pid_t p4=fork();
		if(p4==-1)
		{
			printf("Error creating process\n");
		}
		else if(p4==0)
		{
			printf("P4 created. I am %d.My parent is %d\n",getpid(),getppid());
			sleep(104);
		}
		sleep(105);
		
	}
	pid_t p2=fork();
	if(p2==-1)
	{
		printf("Error creating process\n");
	}
	else if(p2==0)
	{
		printf("P2 created. I am %d.My parent is %d\n",getpid(),getppid());
		sleep(106);
	}
}
