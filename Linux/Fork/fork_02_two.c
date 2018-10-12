#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Before Fork  PID = %d\n",getpid());

	pid_t pid = fork();

	if(pid == 0)
	{
		printf("Child PID = %d , MyParent PID = %d\n",getpid(),getppid());
	}
	else
	{
		printf("Parent PID = %d  , MyChild PID = %d \n",getpid(),pid);
		pid_t pid2 = fork();
		if(pid2 == 0)
		{
			printf("Child2 PID = %d , MyParent PID =%d\n", getpid(),getppid());
		}
		else
		{
			printf("Parent Creat 2 PID = %d , MyChild 2 = %d\n", getpid(), pid2);
			sleep(2);
		}
	}
	printf("Hehe\n");
	exit(0);
}
