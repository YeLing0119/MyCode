#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>
#include <ctype.h>

int main(){
    while(1){
        char cmd[1024] = {0};
        printf("<Yeling0119 @ MiniShell>:");
        fflush(stdout);
        //%[^\n] 从scanf读取缓冲区时，遇到\n终止读取
        //%*c  将剩下的字符从缓冲区取出来丢到
        //scanf("%s-%s",d1, d2);    // 10-20
        if(scanf("%[^\n]%*c", cmd) != 1){
            getchar();
        }
        char *ptr = cmd;
        char *argv[32] = {NULL};
        int argc = 0;
        while(*ptr != '\0'){
            if(!isspace(*ptr)){
                argv[argc++] = ptr;
                while(!isspace(*ptr) && *ptr != '\0'){
                    ptr++;
                }
                continue;
            }else{
                *ptr = '\0';
            }
            ptr++;
        }

        printf("Cmd : [%s] " , argv[0]);
        for(int i = 1 ;i < argc ; i++){
            printf("[%s]",argv[i]);
        }

        printf("\n");

        pid_t pid = fork();

        if(pid == 0){
            execvp(argv[0],argv);
        }else if (pid > 0){
            wait(NULL);
        }else{
            printf("Fork Failure\n");
        }
    }
    return 0;
}
