#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a[500]={0};
	printf("Total memory is : %d\n",500);
	
	int ch=1;
	while(ch==1)
	{
		printf("Enter start point and file size...\n");
		int start,size;
		scanf("%d %d",&start,&size);
		int i,flag=0;
		for(i=start;i<start+size;i++)
		{
			if(a[i]==1)
			{
				flag=1;break;
			}
		}
		if(flag==1)
		printf("Nospace....Retry.\n");
		else
		{
			for(i=start;i<start+size;i++)
			{
				a[i]=1;
			}
			printf("Stored\n");
		}
		
		printf("More files 1-yes 2-no...");
		scanf("%d",&ch);
	}
}
