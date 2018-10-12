#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int g_data = 250;

int main(void)
{
	pid_t pid = fork();
	
	if (pid == 0){
		printf("child g_data = %p\n", &g_data);
		printf("child g_data_value = %d\n", g_data);
		g_data = 520;
		printf("child g_data_value = %d\n", g_data);
	}else{
		sleep(1);
		printf("parent g_data = %p\n", &g_data);
		printf("parent g_data_value = %d\n", g_data);
	}
	exit(0);
}
