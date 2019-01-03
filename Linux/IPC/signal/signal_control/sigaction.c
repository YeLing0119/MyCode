/*  这是一个演示sigaction接口的demo
 *  功能: 改变信号的默认处理方式
 *  
 *  int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
 *
 *  参数: 
 *      signum: 信号值
 *      act: 新的处理方式
 *      oldact: 旧的处理方式
 *  返回值:
 *      成功: 0
 *      失败: -1
 *  参数中的结构体:
 *      struct sigaction {
 *          void     (*sa_handler)(int);    // 第一种处理方式
 *          void     (*sa_sigaction)(int, siginfo_t *, void *);   // 第二种处理方式
 *          sigset_t   sa_mask;     // 位图 标记临时阻塞的信号
 *          int        sa_flags;    // 定义信号的行为
 *          void     (*sa_restorer)(void); // 预留
 *      };
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void sb_sg_handler(int signum){
    printf("This is sa_handler..%d..\n", signum);
}

void sa_sg_handler(int signum, siginfo_t *siginfo, void *data){
    printf("This is sa_sigaction....%d...\n", signum);
}

int main(){
    struct sigaction act, oldact;
    act.sa_handler = sb_sg_handler;
    //act.sa_sigaction = sa_sg_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;

    sigaction(SIGSEGV, &act, &oldact);

    while(1){
        printf("Sleeping.....\n");
        sleep(1);
    }
}
