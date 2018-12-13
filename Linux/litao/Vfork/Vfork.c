#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int add(int a, int b)
{
	printf("加法\n");
	printf("%d + %d = %d\n",a ,b ,a+b);
}

int g_data = 10;

int main()
{
	pid_t pid = vfork();
	
	if ( pid == -1 )
		perror("vfork"),exit(1);
	
	if ( pid == 0 ){
		sleep(1);
		g_data = 250;
		printf("child play\n");
		add(10 , 20);
		sleep(1);
	}else{
			printf("parent wait child  g_data = %d\n", g_data);	
	}
	exit(0);
}
