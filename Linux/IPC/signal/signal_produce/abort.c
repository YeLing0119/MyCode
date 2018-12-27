/*	这是一个演示 信号中abort接口的 demo
 *	void abort( void );
 *	功能:给自己发送SIGABRT信号
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
	while(1){
		static int i = 0;
		if(i == 3){
			abort();	//3秒后给自己发送终止信号
		}	
		printf("Sleeping...\n");
		sleep(1);
		i++;
	}
}
