#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

static int alarm_fired;

void Ding(int sig)
{
    printf("get a signal %d\n",sig);
    alarm_fired=1;
}

int main()
{
    pid_t pid;
    int return_code=0;
    
    printf("Alarm application starting!\n");

    pid = fork();
    switch(pid)
    {
        case -1:
            perror("Fork failure!\n");
            exit(0);
        case 0:
            sleep(5);
            kill(getppid(),SIGALRM);
            return_code=20;
            printf("return_code:%d\n",return_code);
            exit(return_code);
    }

    printf("waitting for alarm go to off\n");

    (void) signal(SIGALRM,Ding);

    pause();
    
    if(alarm_fired)
        printf("Ding Ding Ding \n");
    printf("alarm return code %d\n",return_code);
    exit(0);
}