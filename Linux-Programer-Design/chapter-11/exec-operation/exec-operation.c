#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	printf("Running ps with execlp!\n");
	execl("/usr/local/nginx/sbin/nginx","nginx",NULL);
	execlp("ps","ps","-aux",NULL);
	printf("Done!\n");
	exit(0);
}
