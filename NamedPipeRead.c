#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
	int res,n;
	char buffer[100];
	res=open("f1",O_RDONLY);
	n=read(res,buffer,100);
	printf("Total bytes read : %d\n",n);
	printf("Content read : %s\n",buffer);
	printf("Process id is : %d\n",getpid());
}
