#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	pid_t pid;
	char *massage;
	int n;
	int exit_code;

	printf("fork program starting!\n");
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork failed!\n");
			exit(1);
		case 0:
			massage="this is a child!\n";
			n=5;
			exit_code=37;
			//exit(0);	//exit();直接结束次进程，之后的不执行
			break;	//break 结束swith语句，之后的还继续执行
		default:
			massage="this is parent!\n";
			n=3;
			exit_code=0;
			break;
	}
	for(;n>0;n--)
	{
		puts(massage);
		sleep(1);
	}

	if(pid != 0)
	{
		int stal_val;
		pid_t child_pid;

		child_pid = wait(&stal_val);

		printf("child has finished , pid = %d\ns",child_pid);

		if(WIFEXITED(stal_val))
			printf("Child exit with code %d \n",WEXITSTATUS(stal_val));
		else
			printf("Child terminated abnormally\n");
	}
	exit(exit_code);
}

