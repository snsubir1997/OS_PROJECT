#include <string.h> // memset
#include <pthread.h> // pthread_t, pthread_create, pthread_join
#include <semaphore.h> // sem_init, sem_wait, sem_post
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//sematphores
sem_t studentSemaphore;
sem_t teachingAssistantSemaphore;

static exit_counter=3;

//sem_t mutex;
pthread_mutex_t mutex;

int chair[3];
int count = 0; //number of waiting students
int next_seat = 0;
int next_teach = 0;

#define NUM_SEAT 3

#define SLEEP_MAX 5

void randomSleep(void);
void* studentCoding(void* stu_id);
void* teacherTeaching();

int main(int argc, char **argv){

	//thread(s)
	pthread_t *students;
	pthread_t ta;
	
	int* s_id;
	int student_num;
	
	//index
	int i;

	//get number of students from user
	printf("Enter no of students coding initially : ");
	scanf("%d", &student_num);

	printf("TEACHING ASSISTANT SLEEPING INITIALLY\n");
	
	//initialize
	students = (pthread_t*)malloc(sizeof(pthread_t) * student_num);
	s_id = (int*)malloc(sizeof(int) * student_num);

	memset(s_id, 0, student_num);

	sem_init(&studentSemaphore,0,0);
	sem_init(&teachingAssistantSemaphore,0,1);
	
	//set random
	srand(time(NULL));

	//sem_init(&mutex,0,1);
	pthread_mutex_init(&mutex,NULL);

	//create thread
	pthread_create(&ta,NULL,teacherTeaching,NULL);

	//create threads for students
	for(i=0; i<student_num; i++)
	{
		s_id[i] = i+1;
		pthread_create(&students[i], NULL, studentCoding, (void*) &s_id[i]);
	} 
	
	pthread_join(ta, NULL);//join teaching assistant thread
	
	//join student threads
	for(i=0; i<student_num;i++)
	{
		pthread_join(students[i],NULL);
	}	
	
	return 0;
}

void* studentCoding(void* stu_id)
{
	int id = *(int*)stu_id;

	printf("Student %d is programming\n",id);		
	
	while(1)
	{
		randomSleep();

		//sem_wait(&mutex);
		pthread_mutex_lock(&mutex);

		if(count < NUM_SEAT)	
		{
			chair[next_seat] = id;
			count++;
			
			printf("Student %d is waiting for doubts to be cleared.\n",id);
			printf("waiting students :\n");
			
			if(chair[0]>0)
			printf("\t Waiting On Chair One Id: %d\n",chair[0]);
			else
			printf("\t Waiting On Chair One Id: NoBody\n");
			if(chair[1]>0)
			printf("\t Waiting On Chair Two Id: %d\n",chair[1]);
			else
			printf("\t Waiting On Chair Two Id: NoBody\n");
			if(chair[2]>0)
			printf("\t Waiting On Chair Three Id: %d\n",chair[2]);
			else
			printf("\t Waiting On Chair Three Id: NoBody\n");
			
			next_seat = (next_seat+1) % NUM_SEAT;
			
			//sem_post(&mutex);
			pthread_mutex_unlock(&mutex);
	
			//wakeup ta
			sem_post(&studentSemaphore);
			sem_wait(&teachingAssistantSemaphore);
		}
		else //no more chairs
		{
			//sem_post(&mutex);
			pthread_mutex_unlock(&mutex);
			
			printf("\nNo more chairs. student %d goes back to coding\n\n",id);		
		}
	}				
}

void* teacherTeaching()
{
	while(1)
	{
		sem_wait(&studentSemaphore);	
		
		//sem_wait(&mutex);
		pthread_mutex_lock(&mutex);
		
		printf("TA is teaching student %d\n",chair[next_teach]);	
		chair[next_teach]=0;
		count--;
		
		printf("waiting students :\n");
		
		if(chair[0]>0)
		printf("\t Waiting On Chair One Id: %d\n",chair[0]);
		else
		printf("\t Waiting On Chair One Id: NoBody\n");
		if(chair[1]>0)
		printf("\t Waiting On Chair Two Id: %d\n",chair[1]);
		else
		printf("\t Waiting On Chair Two Id: NoBody\n");
		if(chair[2]>0)
		printf("\t Waiting On Chair Three Id: %d\n",chair[2]);
		else
		printf("\t Waiting On Chair Three Id: NoBody\n");
			
			next_teach = (next_teach + 1) % NUM_SEAT;
		
		randomSleep();
		
		if(chair[0]==0 && chair[1]==0 && chair[2]==0)
		{
			printf("TEACHING ASSISTANT SLEEPING AGAIN\n");
			exit_counter--;
			if(!exit_counter)
			{
				printf("\n\nDAY ENDS.EVERYONE HOME");
				exit(0);
			}
		}
		//sem_post(&mutex);
		pthread_mutex_unlock(&mutex);

		sem_post(&teachingAssistantSemaphore);
	}	
}

void randomSleep(void)
{
	
	int time = rand() % SLEEP_MAX + 1;
	sleep(time);
}
