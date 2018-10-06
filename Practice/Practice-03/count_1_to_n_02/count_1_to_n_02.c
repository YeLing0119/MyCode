#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count = 1;
	double result = 0;
	printf("计算 1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的结果\n");
	for(; count <= 100; count++)
	{
		if(count%2 == 0)
		{
			result -= 1.0/count;
		}
		else
		{
			result += 1.0/count;
		}
	}
	printf("result = %lf\n",result);
	exit(0);
}
