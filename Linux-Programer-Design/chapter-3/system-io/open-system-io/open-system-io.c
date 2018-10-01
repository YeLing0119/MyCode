#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
    char c;
    int in_fd,out_fd;

    in_fd = open("file.in",O_RDONLY);
    out_fd = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
    printf("%d %d \n",in_fd,out_fd);
    while(read(in_fd,&c,1)==1)
        write(out_fd,&c,1);
	
    exit(0);
}
