#include<stdio.h>
#include<stdlib.h>

int main()
{
	int count = 0;
	for(int i = 101 ; i <= 200 ; i+=2)
	{
		for(int j = 2 ; j < i ; j++)
		{
			if(i % j == 0)count++;
		}
		if(count == 0)
			printf("%d  ",i);
		count = 0;
	}
	printf("\n");
	exit(0);
}
