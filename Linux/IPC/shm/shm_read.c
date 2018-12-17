#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main(){
  int key = 1234;
  int shmid = shmget(key, 1024, 0);

  if(shmid == -1){
    printf("Get shm Failed\n");
    perror("shmget");
  }

  char *ptr = (char *)shmat(shmid, NULL, 0);
  if(ptr == (void *)-1){
    printf("Memory Mapping Failed\n");
    perror("shmat");
  }
  
  char buf[1024] = {0};
  //while(1){
    memcpy(buf, ptr, 1024);
    printf("Get Information : %s", buf);
  //  sleep(1);
  //}    
  int ret = shmdt(ptr);

  if(ret == -1){
    printf("Failed Uninstall\n");
    perror("shmdt");
  }
 
  ret = shmctl(shmid, IPC_RMID, NULL);

  if(ret == -1){
    printf("Failed Delete \n");
  }

  //printf("Get Information : %s", buf);
}
