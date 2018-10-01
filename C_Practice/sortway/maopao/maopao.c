#include<stdio.h>

int main()
{
    int ch[5]={20,56,85,65,24};
    for( int i=0;i<4;i++)
    {
        for( int j=0;j<4-i;j++)
        {
            if(ch[j]>ch[j+1])
            {
                int tmp=ch[j];
                ch[j]=ch[j+1];
                ch[j+1]=tmp;
            }
        }
    }

    for(int i=0;i<5;i++)
    {
        printf("%d\n",ch[i]);
    }
    return 0;
}