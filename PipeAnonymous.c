#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	int fd[2];
	char buffer[100];
	pipe(fd);
	
	pid_t p=fork();
	
	if(p==-1)
	printf("ForkFail...\n");
	else if(p>0)
	{
		close(fd[0]);
		printf("Write to pipe...\n");
		write(fd[1],"Hello\n",6);
		sleep(1);
	}
	else
	{
		close (fd[1]);
		printf("Read from pipe...\n");
		int n=read(fd[0],buffer,100);
		write(1,buffer,n);
	}
}
