#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>

void sigbc(int signo){
    waitpid(-1, NULL, WNOHANG);
    printf("child is exit:\n");
}

int main(){
    signal(SIGCHLD, sigbc); //  设置SIGCHLD信号处理函数、用于回收僵尸子进程

    int fds[2];
    int ret = pipe(fds);
    if(ret == -1){
        //创建管道失败
        perror("pipe");
    }

    pid_t pid = fork();
    if(pid == -1){
        // fork 失败
        perror("fork");
        exit(1);
    }else if(pid == 0){
        // 子进程，读取管道中的内容
        close(fds[1]);  //  子进程关闭写
        char buf[1024] = {0};
        int n = 2;
        while(n--){
            if(read(fds[0], buf, 1023) == 0){   // 若写端完全关闭，read返回0
                printf("All Write already closed\n");
                break;
            }else{
                printf("reading......");
            }
            printf("%s\n", buf);
        }
        close(fds[0]);  // 读两次后关闭读端
    }else{
        //父进程
        close(fds[0]);  //  父进程关闭读
        char *buf = "hahahahahahaha";
        write(fds[1], buf, 1023);
        close(fds[1]);  //写完立即关闭写端
        while(1){
            //write(fds[1], buf, 1023);
            sleep(1);
        }
    }
    close(fds[0]);
    close(fds[1]);
}