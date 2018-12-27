/* 	这是一个演示信号中raise借口的demo
 * 	int raise(int signo)
 * 	功能:给自己发送一个指定的信号
 * 	参数:
 * 		signo:信号值
 * 	返回值：
 * 		成功:0
 * 		失败:非0
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(){
	while(1){
		static int i = 0;
		if(i == 3){
			raise(SIGSEGV);		//睡3秒后给自己发送 SIGSEGV 信号
		}
		printf("Sleeping...\n");
		sleep(1);
		i++;
	}
}
