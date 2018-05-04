#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	FILE *rd;
	char buffer[100];
	rd=popen("wc -c","r");
	fread(buffer,1,50,rd);
	printf("%s\n",buffer);
	pclose(rd);
}
