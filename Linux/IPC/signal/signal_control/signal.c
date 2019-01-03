/*	这是一个演示 signal 接口的demo
 *	
 *	typedef void (*sighandler_t)(int);
 *	sighandler_t signal(int signum, sighandler_t handler);
 *	
 *	功能: 设置指定信号的处理函数
 *	参数: 
 *		signum: 要设置的信号
 *		sighandler_t handler: 具体的处理方式 注意:  sighandler_t 是一个函数指针类型
 *			1. SIG_IGN : 该信号将被忽略
 *			2. SIG_DFL : 该信号将使用默认的处理函数
 *			3. 自己编写该信号的处理函数
 *
 *	返回值:
 *		成功: 返回上一次的处理函数
 *		失败: SIG_ERR
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void int_handle(int signo){
    printf("I Got A Signal %d \n", signo);
}

int main(){
    typedef void (*sighandler_t)(int);	
    //sighandler_t old = signal(SIGINT, SIG_IGN);		// 该信号将被忽略，现象就是Ctrl + C 无法使程序中断
    //sighandler_t old = signal(SIGINT, SIG_DFL);	// 使用该信号的默认处理方式
    sighandler_t old = signal(SIGINT, int_handle);	// 使用自定义的信号处理方式
    if(old == SIG_DFL){
        printf("---------------------------------\n");
        sleep(2);
    }
    while(1){
        printf("Sleeping...\n");
        sleep(1);
    }
}
