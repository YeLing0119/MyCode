#include<unistd.h>
#include<stdlib.h>

int main()
{
    if((write(1,"Here are some data\n",18))!=18)
        write(2,"A write error has occoured on file descriptor 1 \n",48);
    exit(0);
}
