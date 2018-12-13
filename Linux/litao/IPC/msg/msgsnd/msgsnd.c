#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>


typedef struct msgbuf{
	long type;
	char str[1024];
}msgbuf_t;

int main(int argc , char *argv[]){
	if(argc != 2){
		fprintf(stderr, "usage : %s type \n", argv[0]);
		exit(0);
	}
	
	int msgid  = msgget(1234, 0);
	if(msgid == -1){
		perror("msgget");
		exit(1);
	}

	msgbuf_t msg;
	memset(&msg ,0x00 , sizeof(msg));
	msg.type = atoi(argv[1]);
	printf("msg : ");
	fgets(msg.str , 1023 , stdin);
	int mr = msgsnd(msgid , &msg , strlen(msg.str), 0);
	if(mr == -1){
		perror("msgsnd");
		exit(0);
	}
	exit(0);
}
