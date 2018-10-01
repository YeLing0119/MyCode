#include<stdio.h>

int main()
{
    int max,ch[10];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&ch[i]);
    }
    max=ch[0];

    for(int i=0;i<10;i++)
    {
        printf("%d\n",ch[i]);
    }
    for(int i=0;i<10;i++)
    {
        if(ch[i]>max)
        {
              max=ch[i];
        }
    }
    printf("max is:%d\n",max);
    return 0;
}