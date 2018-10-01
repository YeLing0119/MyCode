#include<stdio.h>
#include<stdlib.h>

void swap(int* a , int* b)
{
	*a = *a + *b ;
	*b = *a - *b ; 
	*a = *a - *b ;
}

int main()
{
	int i,j;
	int ch[]={3,5,2};
	for(i = 0 ; i < 2 ; i++)
		for(j = 0 ; j < 2 - i ; j++)
			if(ch[j]>ch[j+1])
			{
				swap(&ch[j],&ch[j+1]);
			}
	for( i = 0 ; i < 3 ; i++)
		printf("%d\n",ch[i]);
	exit(0);
}
