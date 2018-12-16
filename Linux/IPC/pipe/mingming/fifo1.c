#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
    char *filename = "./test.fifo";

    int fd = open(filename, O_WRONLY);

    if(fd == -1){
        perror("open");
        exit(0);
    }
    char *buf = "dasdasdasdasdas";

    int n = 5;
    while(n--){
        write(fd, buf, 1023);
        sleep(1);
    }

    close(fd);
    return 0;
}