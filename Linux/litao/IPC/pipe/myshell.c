#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_LINE 1024
#define	MAX_ARGV 12

char cmdline[MAX_LINE+1];
char argvline[MAX_LINE+1];

typedef struct cmd{
	char* argv[MAX_ARGV];
}cmd_t;

cmd_t command;

void init(){
	memset(cmdline, 0x00, sizeof(cmdline));
	memset(argvline, 0x00, sizeof(argvline));
	memset(&command, 0x00, sizeof(command));	
}

int Read_Cmd(){
	printf("MyShell => ");
	return fgets(cmdline, MAX_LINE, stdin) == NULL ? 0 : 1;
}

void Parse_Cmd(){
	char* p = cmdline;
	char* q = argvline;
	int argc = 0;
	
	while(*p != '\0'){
		while(isspace(*p) && (*p) != '\0'){
			p++;
		}
		if(*p == '\0'){
			break;
		}
		command.argv[argc] = q;
		argc++;
		while(*p != '\0' && !isspace(*p)){
			*q++ = *p++;
		}
		*q++ = '\0';
	}
	command.argv[argc] == NULL;
}

void PrintCmd(){
	int i = 0;
	for(; command.argv[i] != NULL; i++){
		printf("\targv[%d] -->  %s \n", i, command.argv[i]);
	}
}

void Execute_Cmd(){
	pid_t pid;
	if((pid = fork()) == 0){
		execvp(command.argv[0],command.argv);
		exit(-1);
	}
	waitpid(pid, NULL, 0);
}

int main(void){
	while(1){
		init();
		if(Read_Cmd() == 0){
			break;
		}
		Parse_Cmd();
		PrintCmd();
		Execute_Cmd();	
	}
	printf("Thanks !\n");
}


