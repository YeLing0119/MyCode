#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

struct msgbuf{
	long type;
	char text[1024];
};

int main(){
	int msgid = msgget(1234, 0);
	if(msgid == -1){
		perror("msgget");
		exit(1);
	}
	
	struct msgbuf mb;
	while(1){
		memset(&mb, 0x00, sizeof(mb));
		mb.type = 1;
		*(int*)(mb.text) = getpid();
		
		//读取键盘
		char* p =fgets(mb.text+sizeof(int),1024-sizeof(int), stdin);
		if(p == NULL){
			break;
		}
		
		//发送给服务器
		msgsnd(msgid, &mb, strlen(mb.text + sizeof(int)) + sizeof(int), 0);
	
		//读取服务器		
		memset(&mb, 0x00, sizeof(mb));
		msgrcv(msgid, &mb, 1024 - sizeof(int), getpid(), 0);
		
		//显示到屏幕	
		printf(":%s",mb.text+sizeof(int));
	}
}
