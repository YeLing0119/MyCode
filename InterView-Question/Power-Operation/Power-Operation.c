#include<stdio.h>

double pow(double R ,double n)
{
    double tmp=1;
    for(int i=0;i<n;i++)
    {
        tmp=R*tmp;
        printf("%lf\n",tmp);
    }
    return tmp;
}

int main()
{
    double R,n;
    printf("%d",(int)sizeof(double));
    printf("请输入R和n\n"); 
    scanf("%lf %lf",&R,&n);
    printf("%lf %lf\n",R,n);
    printf("%.36lf\n",pow(R,n));
    return 0;
}
