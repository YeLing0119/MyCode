#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
	int msgid = msgget(1234,IPC_CREAT|0664);
	if(msgid = -1){
		perror("msgget"),exit(1);
	}
	printf("msgget create success\n");
	
	
}
