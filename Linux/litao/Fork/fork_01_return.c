#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("Before Fork\n");
	
	pid_t pid = fork();
	
	if (pid == 0)
	{
		printf("child\n");
	}
	else if (pid > 0)
	{
		printf("parent\n");
	}
}


