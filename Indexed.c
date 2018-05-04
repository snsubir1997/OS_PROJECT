#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[100][100]={0};
    
    printf("Total size...100*100\n");
    
    int ch=1;
	while(ch==1)
	{
		printf("Enter start point and file size...\n");
		int start,size;
		scanf("%d %d",&start,&size);
		
		if(a[start][0]!=0)
		printf("No space here...Retry\n");
		else
		{
			if(size>99)
			printf("No space...Retry\n");
			else
			{
				int i;
				for(i=1;i<=size;i++)
				a[start][i]=1;
				a[start][0]=size+1;
				printf("Stored\n");
			}
		}
		
		printf("More files 1-yes 2-no...");
		scanf("%d",&ch);
	}
}
