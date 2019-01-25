#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *pthread_enter(void *data){
    
    printf(" This is child pthread and get data is %p\n", data);
    sleep(5);

    pthread_cancel((pthread_t)data); 
    while(1){
        static int i = 0;
        printf("----------\n");
        sleep(1);
        i++;
        if(i == 5){
            printf(" time out : break\n");
            break;
        }
    }
    pthread_exit((void *)-1);
    return NULL;
}

int main(){
    pthread_t pthread;

    int ret = pthread_create(&pthread, NULL, &pthread_enter, (void*)pthread_self());
    if(ret != 0){
        printf("Create thread failure\n");
        exit(-1);
    }

    while(1){
        sleep(1);
    }
    
    return 0;
}
