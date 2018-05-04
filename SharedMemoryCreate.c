#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>

void main()
{
	int shmid;
	char buffer[100];
	void *shared_memory;

	shmid=shmget((key_t)2345,1000,0666|IPC_CREAT);
	printf("Key is : %d\n",shmid);

	shared_memory=shmat(shmid,NULL,0);
	printf("Process attached at : %X\n",(int)shared_memory);
	
	printf("Data to be written to shared memory\n");
	read(0,buffer,100);
	strcpy(shared_memory,buffer);
	printf("You wrote %s to shared memory.\n",shared_memory);
}
