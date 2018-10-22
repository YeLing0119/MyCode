#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int fds[2];
	
	if(pipe(fds) == -1)
		perror("pipe"),exit(1);
		
	pid_t pid = fork();
	if(pid == -1)
		perror("fork"),exit(1);
	if(pid == 0){	//子进程往管道里面写
		close(fds[0]);
		write(fds[1],"abc", 3);
		close(fds[1]);
	}else{		//父进程读取管道里面的数据
		close(fds[1]);
		char buff[100] = {};
		int r = read(fds[0],buff,100);
		if( r == 0)
			printf("Read EOF\n");
		else if( r == -1 )
			perror("read"),exit;
		else if( r > 0 )
			printf("buff = [%s]\n",buff);
		close(fds[0]);
		exit(0);
	}

}
