/*	这是一个演示 信号中sigqueue接口的demo
 *	int sigqueue(pid_t pid, int sig, const union sigval value);
 *	功能: 向指定和进程发送指定的信号，并且携带一个联合体参数
 *	参数:
 *		pid: 进程id号
 *		sig: 信号
 *		union sigval value: sigval 联合体 携带的联合体参数
 *			union sigval{
 *				int sival_int;
 *				void* sival_ptr;
 *			};
 *	返回:
 *		成功: 0
 *		失败: -1, 并且设置errno	
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	while(1){
		printf("Error , This Function not Implement  \n");
		sleep(1);
	}
}
