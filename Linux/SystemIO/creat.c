#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int fd = open("abc", O_CREAT|O_RDWR|O_EXCL, 0666);
	if(fd == -1){
		fd = open("abc", O_RDWR);
		if(fd == -1){
			perror("open");
			exit(0);
		}
	}

	char *msg = "mmc" ;
	int r = write(fd, msg, strlen(msg));
	printf("len = %d , r = %d \n", strlen(msg), r );
	close(fd);
}
