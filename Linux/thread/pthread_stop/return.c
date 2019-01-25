/*  这是一个演示在线程中使用return退出的demo
 *
 *      在线程中使用 return 则谁调用谁退出
 *      在主线程使用 return 则退出整个进程(包括由主线程创建的线程)
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

void *pthread_enter(void * data){
    int i = 0;
    while(1){
        printf("This is child thread \n get a data is %p \n", data);
        sleep(1);
        i++;
        if(i == 5){
            printf(" Quit reason : time arrived\n");
            return NULL;        // 在子线程中使用 return 退出
        }
    }
}

int main(){
    pthread_t pthread;
    int ret = pthread_create(&pthread, NULL, &pthread_enter, (void *)0x11223344);
    if(ret != 0){
        printf("Create thread failure\n");
    }
    
    sleep(10);          // 保证线程可以先调用return 退出
    
    return 0;       // 在主线程中 慎用 return 
                    // 因为在主线程中退出意味着终止当前程序 将退出整个程序，包括创建的线程
}
