#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd = open("open.c",O_RDONLY);
	if(fd == -1){
		perror("open");
	}else{
		printf("Open Successful \n");
		printf("fd = %d\n", fd);
	}
	while(1){
		char buf[2] = {};
		int r = read(fd , buf , 1);
		if (r == -1){
			perror("read");
		}else if(r == 0){
			printf("读结束\n");
			break;
		}else{
			printf("%s", buf);
			fflush(stdout);
		}
		usleep(50000);
	}
	close(fd);
}
