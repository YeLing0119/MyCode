#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void ouch(int sig)
{
    printf("OUCH - I got a signal %d\n",sig);
}

int main()
{
    struct sigaction act;

    act.sa_handler=ouch;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;

    sigaction(SIGINT,&act,0);

    while(1){
        printf("waitting signal ....\n");
        sleep(1);
    }
}