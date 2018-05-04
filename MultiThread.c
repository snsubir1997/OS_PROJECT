#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
//#include<sys/shm.h>

struct ar
{
	int x,y;
};

int *add(void *ar)
{
	struct ar *a=ar;
	return (a->x+a->y);
}
int *sub(void *ar)
{
	struct ar *a=ar;
	return a->x-a->y;
}
int *mul(void *ar)
{
	struct ar *a=ar;
	return a->x*a->y;
}
int *divi(void *ar)
{
	struct ar *a=ar;
	return a->x/a->y;
}

void main()
{
	pthread_t p1,p2,p3,p4;
	
	struct ar a;
	printf("Enter values...\n");
	printf("Enter x...\n");
	scanf("%d",&a.x);
	printf("Enter y...\n");
	scanf("%d",&a.y);
	
	
	
	void *res;
	pthread_create(&p1,NULL,add,&a);
	pthread_join(p1,&res);
	printf("Sum is : %d\n",res);
	
	pthread_create(&p2,NULL,sub,&a);
	pthread_join(p2,&res);
	printf("Diff is : %d\n",res);
	
	pthread_create(&p3,NULL,mul,&a);
	pthread_join(p3,&res);
	printf("Product is : %d\n",res);
	
	pthread_create(&p4,NULL,divi,&a);
	pthread_join(p4,&res);
	printf("Quotient is : %d\n",res);
}
