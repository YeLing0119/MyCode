#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main( void ){
	int fd = open ("abc", O_RDWR);
	pid_t pid = fork();
	if ( pid == 0){
		sleep(2);
		if( write(fd, "mmc", 3) == -1)
			perror("write"),exit(1);
		close(fd);
	}else{
		char buf[4] = {};
		read(fd, buf, 3);
		printf("buf = [%s]\n", buf);		           		
		close(fd);
	}                 		
}                     		
                      		
