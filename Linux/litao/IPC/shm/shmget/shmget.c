#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>

struct student{
	int shmid;
	char name[20];
};

int main(){
	int shmid = shmget(1234, sizeof(struct student), IPC_CREAT|0664);
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	printf("Shmget : Success\n");
}
