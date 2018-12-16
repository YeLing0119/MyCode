#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
	key_t key = 1234;

	int handle = shmget(key, 1024, IPC_CREAT|0664);

	
}
