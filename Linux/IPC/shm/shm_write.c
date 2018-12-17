#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(){	
	int key = 1234;
	// 创建共享内存
	int shmid = shmget(key, 1024, IPC_CREAT|0664);
	//int handle = shmget(shmid, 1024, 0);

	if(shmid == -1){
		printf("Get Shared Memory Failed\n");
		perror("shmget");
		return 0;
	}
  
	// 把共享内存映射到自己的共享区
	char *ptr = (char *)shmat(shmid, NULL, 0);

	if(ptr == (void *)-1){
		printf("Memory Mapping Failed\n");
    perror("\n");
		return 0;
	}
		
	// IO操作
	char *str = "This is testing Shared Memory\n";
	//while(1){
    memcpy((char *)ptr, str, strlen(str));
  //  sleep(1);
  //}

	// 把共享内存从共享区卸载
	int ret = shmdt(ptr);
	
	if(ret == -1){
		printf("Failed Delete\n");
		perror("\n");
	}

	// 关闭共享内存
//ret = shmctl(shmid, IPC_RMID, NULL);
//if(ret == -1){
//	printf("Close SHM Failed\n");
//	perror("\n");
//	return 0;	
//}

	while(1){
    sleep(1);
	}
}
