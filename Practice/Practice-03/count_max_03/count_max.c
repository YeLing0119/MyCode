#include<stdio.h>
#include<stdlib.h>

int max(int a , int b)
{
	return a>b?a:b;
}

int main()
{
	int ch[10] = {5,2,3,6,8,10,8,9,2,6};
	int max = 0 ;
	for(int i ; i < 10 ; i++)
	{
		if(max<ch[i])
			max = ch[i];
	}
	printf("Max = %d \n" , max);
	exit(0);
}
