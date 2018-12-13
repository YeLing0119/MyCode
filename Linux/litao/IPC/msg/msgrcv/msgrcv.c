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
	
	int msgid = msgget(1234, 0);
	if(msgid == -1){
		perror("msgrcv");
		exit(1);
	}
	
	msgbuf_t mr;
	memset(&mr , 0x00 , sizeof(mr));
	ssize_t mrr = msgrcv(msgid , &mr , 1023 , atoi(argv[1]), 0);
	if(mrr == -1){
		perror("msgrcv");
		exit(1);
	}
	
	printf("%s" , mr.str);

	exit(0);
}
