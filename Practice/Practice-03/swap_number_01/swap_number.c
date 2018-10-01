#include<stdio.h>
#include<stdlib.h>

//创建变量交换
void swap(int* a , int* b )
{
	int tmp ;
	tmp = *a ;
 	*a = *b ;
	*b = tmp ;
}


int main()
{
	int a = 5, b = 8 ;
	printf("a = %d  b = %d\n", a, b);
	swap(&a,&b) ;
	printf("a = %d  b = %d\n", a, b);
}
