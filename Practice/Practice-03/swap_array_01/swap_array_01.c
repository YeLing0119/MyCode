#include <stdio.h>
#include <stdlib.h>

void SwapNum(int* a , int* b)
{
	int c = *a ;
	*a = *b ;
	*b = c ;
}

void SwapArray(int arr1[],int arr2[],int len)
{
	int i = 0 ;
	for(;i<len;i++)
	{
		SwapNum(&arr1[i],&arr2[i]);
	}
}

int main()
{
	int i;
	int ch[]={1,2,3,4,5,6,7,8,9,0};
	int sh[]={0,9,8,7,6,5,4,3,2,1};
	int len = sizeof(ch)/sizeof(ch[0]);
	
	printf("交换前......\n");	
	for(i = 0 ; i < len ; i++)
	{
		printf("%d  ",ch[i]);
	}
	printf("\n");
	for(i = 0 ; i < len ; i++)
	{
		printf("%d  ",sh[i]);
	}
	printf("\n");
	
	SwapArray(ch,sh,len);
	
	printf("交换后......\n");
	for(i = 0 ; i < len ; i++)
	{
		printf("%d  ",ch[i]);
	}
	printf("\n");
	for(i = 0 ; i < len ; i++)
	{
		printf("%d  ",sh[i]);
	}
	printf("\n");
	exit(0);
}
