#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<sys/shm.h>

void main()
{
	int shmid,i;
	char buffer[100];
	void *shared_memory;

	shmid=shmget((key_t)2345,1000,0666);
	printf("Key id : %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("Process at %X\n",(int)shared_memory);
	printf("Data from shared memory is %s\n",shared_memory);
}
