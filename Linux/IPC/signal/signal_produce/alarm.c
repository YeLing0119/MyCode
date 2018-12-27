/*  这是一个演示 信号中alarm接口的demo
 *	unsignal int alarm(unsignal int second)
 *	功能: 
 *		指定时间后给自己发送一个alarm信号
 *	参数:
 *		second: 秒数
 *	返回值:
 *		上一个alarm未执行完的秒数
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_alarm(int signo){
	printf("I Got a signal %d \n", signo);
}

int main(){
	
	signal(SIGALRM, my_alarm);
	
	int ret = alarm(5);		//在此时期，没有alarm调用，所以此处ret = 0;
	printf("Ret = %d\n", ret);
	sleep(2);
	ret = alarm(5);		//在此之前，有alarm调用，所以返回上次调用剩余的秒数，所以此处ret = 3
	printf("Ret = %d\n", ret);
	sleep(10);
	ret = alarm(1);		//在此之前有alarm调用，但是该调用的时间已经到了，所以此处ret = 0
	printf("Ret = %d\n", ret);
	return 0;
}
