#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	int res;
	res=mkfifo("f1",0777);
	printf("Names pipe created...\n");
}
