#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ouch(int sig)
{
    printf("ouch! -  your computer will shutdown!\n");
}

int main()
{
    pid_t pid;
    int i=10;

    (void) signal(SIGINT,ouch);
    
    printf("got pid is %d",pid);
    
    while(i>0){
        printf("waiting %d ..... \n",i);
        kill(pid,SIGINT);
        sleep(1);
        i--;
        if(i==0)
            execlp("ps","ps","-aux",0);
            //(void) signal(SIGINT,SIG_DFL);
    }
}