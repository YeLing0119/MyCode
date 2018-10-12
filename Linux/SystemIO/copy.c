#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

//usage : copy src dst
int main(int argc , char* argv[]){
	if(argc != 3 ){
		fprintf(stderr,"usage : %s src dst \n", argv[0]);
		exit(1);
	}
	//打开源文件
	int fd_src = open (argv[1], O_RDONLY);
	if(fd_src == -1 ) perror("open"),exit(0);
	
	// 打开目标文件 ，若不存在则创建
	int fd_dst = open (argv[2], O_CREAT|O_RDWR|O_EXCL, 0644);
	if(fd_dst == -1 && errno == EEXIST ){
		printf("目标存在，是否覆盖(Y/N)\n");
		char choose ;
		scanf(" %c", &choose);
		if(choose == 'Y' || choose == 'y'){
			fd_dst = open(argv[2],O_RDWR);
			if(fd_dst == -1)perror("open"),exit(1);
		}else{
			exit(0);
		}
	}
	
	//循环读取源文件，写入目标文件
	char buf[1024+1];
	while(1){
		memset(buf, 0x00 , sizeof(buf));
		int r = read(fd_src, buf, 1024);
		
		if(r <= 0)break;
		
		write(fd_dst, buf, r);
	}

	//关闭文件
		
	close(fd_src);
	close(fd_dst);
}
