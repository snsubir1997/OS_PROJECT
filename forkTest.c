#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int flag1=0,flag2=0;
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        wait();
        printf("\nRight Child %d %d",getpid(),getppid());
        pid_t child;
        child=fork();
        if(child==0)
        {
           
            wait();
            printf("\nRight Right Child %d %d",getpid(),getppid());
        }
        else
        {
            child=fork();
            if(child==0)
            {
                printf("\nRight Left Child %d %d",getpid(),getppid());
            }
        }
    }
    else
    {
       
        printf("\n\n\n");
        pid=fork();
        if(pid==0)
        {
            pid_t child;
            printf("\nLeft Child %d %d",getpid(),getppid());
            child=fork();
            if(child==0)
            {
                wait();
                printf("\nLeft Right Child %d %d",getpid(),getppid());   
            }
            else
            {
                printf("\nLeft Child %d %d",getpid(),getppid());
                child=fork();
                if(child==0)
                {
                    printf("\nLeft Left Child %d %d",getpid(),getppid());
                }
            }       
        }
        else
        {
        }
    }
}
