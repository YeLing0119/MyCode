/*	这是一演示 信号中kill借口使用的demo
 *	
 *	kill(pid_t pid, int signo)
 *	功能: 给指定的进程发送指定的信号，也可以给自己发送
 *	参数: 
 *		pid: 接收信号的进程的id
 *		signo: 具体的信号
 *	返回值:
 *		成功: 0
 *		失败: -1, 并且设置errno
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

	signal(SIGALRM, ohoh);	//重新设置信号的处理方式
	
	if(pid == -1){
		// 出错
		printf("fork failure\n");
		exit(-1);
	}else if(pid == 0){
		// 子进程
		while(1){
			static int i = 0;
			if(i == 5){
				kill(getppid(), SIGSEGV); //杀死父进程
				kill(getpid(), SIGKILL);	//杀死自己
			}
			printf("Child Sleeping...\n");
			sleep(1);
			i++;
		}
	}else{
		// 父进程
		while(1){
			printf("Parent Sleeping...\n");
			sleep(1);
		}	
		//kill(pid, SIGALRM);		//杀死子进程
	}
	return 0;
}
