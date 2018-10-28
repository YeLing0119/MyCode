#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count = 0;
	int number_9 = 0;
	
	for(; count < 100; count++)
	{
		if(count%10 == 9)
		{
			number_9++;
		}
		if(count / 10 == 9)
		{
			number_9++;
		}
	}
	printf("出现%d次 9 ", number_9);
	exit(0);
}
