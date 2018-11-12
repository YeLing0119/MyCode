#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
	int shmid = shmget(1234, 0 , 0);
	shmctl(shmid, IPC_RMID, NULL);
}
