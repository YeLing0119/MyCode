#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    char *filename = "./test.fifo";
    umask(0);
    int ret = mkfifo(filename, 0664);

    if(ret == -1){
        perror("mkfifo");
        if(errno != 1){
            exit(0);
        }
    }

    int fd = open(filename, O_RDONLY);

    if(fd == -1){
        perror("open");
        exit(0);
    }

    char buf[1024] = {0};

    while(1){

        if(read(fd, buf, 1023) == 0){
            break;
        }
        printf("read : [%s]\n", buf);
    }

    close(fd);
    return 0;
}