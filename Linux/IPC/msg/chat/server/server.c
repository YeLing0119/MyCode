#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msgbuf{
	long type;
	char text[1024];
};

int main(){
	int msgid = msgget(1234, IPC_CREAT|0664);
	if(msgid == -1){
		perror("msgget");
		exit(1);
	}
	
	struct msgbuf mb;
	while(1){
		memset(&mb, 0x00, sizeof(mb));
		//读取类型为1的消息
		int mr = msgrcv(msgid, &mb , 1024, 1, 0);
		if(mr == -1){
			perror("msgget");
			exit(1);
		}
		mb.type  = *(int *)(mb.text);
		//发送
		msgsnd(msgid , &mb , strlen(mb.text + sizeof(int)) + sizeof(int), 0);
				
	}
}
