#include<stdio.h>

#define MAXARRAYSIZE 20

int main()
{
    int ch[MAXARRAYSIZE];
    for(int i=0;i<10;i++)
    {
        ch[i]=i;
    }
    for(int i=0;i<10;i++)
    {
        printf("%d\n",ch[i]);
    }
    return 0;
}