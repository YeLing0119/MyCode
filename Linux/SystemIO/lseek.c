#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(){
	int fd = open("abc", O_RDONLY);
	if(fd == -1) perror("open"),exit(1);
	
	while(1){
		char c;
		if(read(fd, &c, 1) <= 0)
			break;
		write(1, &c, 1);
		lseek(fd, 1, SEEK_CUR);
	}
	printf("%d\n", lseek(fd, 0, SEEK_END));
	close(fd);
}
