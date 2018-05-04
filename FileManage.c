#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

void main()
{
	int n,x;
	char buff[100];
	n=read(0,buff,100);
	
	FILE *fd=open("abc",O_CREAT|O_RDWR,0777);
	write(fd,buff,n);

	close(fd);


	FILE *fd1=open("abc",O_RDONLY);
	FILE *fd2=open("abccopy",O_CREAT|O_RDWR,0777);
	char buffer[100];

	while((x=read(fd1,buffer,1))!=0)
	{
		write(fd2,buffer,x);
	}

printf("File copy completed.\n");
}
