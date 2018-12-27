/*
 *	这是一演示信号中kill借口使用的deamo
 *	kill(pid_t pid, int signo)
 *		给指定的进程发送指定的信号，也可以给自己发送
 */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void ohoh(int signo){
	printf("hahahahahahaha\n");
}

int main(){
	pid_t pid = fork();

	signal(SIGALRM, ohoh);
	
	if(pid == -1){
		// 出错
		printf("fork failure\n");
		//exit(0);
	}else if(pid == 0){
		// 子进程
		while(1){
			static int i = 0;
			if(i == 10){
				kill(getpid(), SIGKILL); //杀死自己
			}
			printf("sleeping...\n");
			sleep(1);
			i++;
		}
		//exit(1);
	}else{
		// 父进程
		sleep(3);	
		//kill(pid, SIGALRM);		//杀死子进程
		//exit(0);
	}
	return 0;
}
