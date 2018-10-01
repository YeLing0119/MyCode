#include<stdio.h>
#include<stdlib.h>


//根据加减调换
void swap_add(int* a , int* b )
{
	*a = *a + *b ;
	*b = *a - *b ;
	*a = *a - *b ;
}

//根据乘除调换
void swap_mul(int* a , int* b)
{
	*a = *a * *b ;
	*b = *a / *b ;
	*a = *a / *b ;
}

int main()
{
	int a = 5 , b = 3;
	printf("a = %d  b = %d \n", a , b);
	swap_add(&a,&b);	
	printf("a = %d  b = %d \n", a , b);
	swap_mul(&a,&b);	
	printf("a = %d  b = %d \n", a , b);
	exit(0);
}
