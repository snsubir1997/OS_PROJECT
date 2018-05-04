#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void main()
{
	FILE *rd;
	char buffer[100];
	sprintf(buffer,"Subir Nandi");
	rd=popen("ls","w");
	fwrite(buffer,sizeof(char),strlen(buffer),rd);
	pclose(rd);
}
