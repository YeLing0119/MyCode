#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
    char c;
    int in,out;

    in = open("file.in",O_RDONLY);
    out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
    if(in==0 && out==0)
        printf("standard input\n");
    if(in==1 && out==1)
        printf("standard output\n");
    if(in==2 && out==2)
        printf("standard error\n");
    else
        printf("input/out/error has occured error!\n");
    printf("%d %d \n",in,out);
    while(read(in,&c,1)==1)
        write(out,&c,1);
    close(1);
    close(2);
    close(3);
    exit(0);
}
