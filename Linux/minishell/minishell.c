#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>
#include <ctype.h>
#include <fcntl.h>

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
        //解析是否有重定向　< <<
        


        char *ptr = cmd;
        char *argv[32] = {NULL};
        int argc = 0;
        //|| *ptr != '>'
        while(*ptr != '\0'){
            if(*ptr == '>'){
                break;
            }
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

        printf("Before fork : %c\n", ptr);

        printf("Cmd : [%s] " , argv[0]);
        for(int i = 1 ;i < argc ; i++){
            printf("[%s]",argv[i]);
        }

        printf("\n");

        pid_t pid = fork();

        if(pid == 0){

            printf("This is child　１　\n");
            //char *ptr = cmd;
            int redirect_flag = -1;
            char *file = NULL;
            while(*ptr != '\0'){
                if(*ptr == '>'){
                    *ptr++ = '\0';
                    redirect_flag = 1;
                    if(*ptr == '>'){
                        *ptr = '\0';
                        redirect_flag = 2;
                    }

                    while(*ptr != '\0' && isspace(*ptr)){
                        ptr++;
                    }

                    file = ptr;
                    while(*ptr != '\0' && isspace(*ptr)){
                        ptr++;
                    }
                    *ptr = '\0'; 
                }
                ptr++;
            }

            printf("File Name : %s\n", file);

            int fd;

            if(redirect_flag == 1){
                fd = open(file, O_CREAT|O_TRUNC|O_WRONLY, 0664);
                dup2(fd,1);
            }

            if(redirect_flag == 2){
                fd = open(file, O_CREAT|O_APPEND|O_WRONLY, 0664);
                dup2(fd,1);
            }

            printf("Rediret : %d   fd : %d\n" , redirect_flag, fd);
            execvp(argv[0],argv);
            
            if(fd >= 0){
                close(fd);
                fd = -1;
            }
        }else if (pid > 0){
            wait(NULL);
        }else{
            printf("Fork Failure\n");
        }
    }
    return 0;
}
