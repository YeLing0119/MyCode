#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *pthread_enter(void *data){
    int i = 0;
    for (i = 0; i < 5; i++){
        printf("wait.....\n");
        sleep(1);
    }
    return NULL;    
}

int main(){
    pthread_t pthread;
    int ret = pthread_create(&pthread, NULL, &pthread_enter, NULL);

    if(ret != 0){
        printf("Create Thread Failure\n");
        return 0;
    }

    //int 

    while(pthread_join() == 0){
        sleep(1);
    }

}
