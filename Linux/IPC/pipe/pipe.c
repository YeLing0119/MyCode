#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
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
    }else{
        //父进程
        close(fds[0]);  //  父进程关闭读
        char *buf = "hahahahahahaha\n"
        write(fds[1], buf, 100);

        while(1){
            sleep(1);
        }
    }
}