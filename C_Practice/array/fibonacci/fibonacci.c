#include<stdio.h>

int main()
{
    int ch[20]={1,1};
    for(int i=2;i<20;i++)
    {
        ch[i]=ch[i-1]+ch[i-2];
    }

    for(int i=0;i<20;i++)
    {
        if(i%5==0)
            printf("\n");
        printf("%5d",ch[i]);
    }
    printf("\n");
    return 0;
}
