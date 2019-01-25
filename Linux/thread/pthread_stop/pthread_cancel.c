#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *pthread_enter(void *data){
    while(1){
        printf("My Thread id is %p\n", (void *)pthread_self());
        printf("This is a child thread : get a data is : %p\n", data);
        sleep(1);
    }
    return NULL;
}

int main(){
    pthread_t pthread;
    int ret = pthread_create(&pthread, NULL, &pthread_enter, (void*)0x11223344);
    if(ret != 0){
        printf("Create thread failure\n");
        strerror(ret);
    }

    while(1){
        static int i = 0;
        if(i == 5){
            printf("speed 5 second kill child thread\n");
            pthread_cancel(pthread);        // 指定取消某一个线程
        }
        printf("speeding %d second \n", i);
        sleep(1);
        i++;
    }
}
