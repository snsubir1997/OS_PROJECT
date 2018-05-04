#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{
	int res,n;
	res=open("f1",O_WRONLY);
	write(res,"hello",5);
	printf("Process %d finished.\n",getpid());
}
