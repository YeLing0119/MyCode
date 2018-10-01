#include<stdio.h>
#include<stdlib.h>

int judge_leap_year(int year)
{
	if((year%4 == 0 && year%100 != 100 ) || year % 400 == 0)
		return 1;
	else 
		return 0;
}

int main()
{
	int judge;
	printf("1.判断1000年---2000年之间的闰年\n2.输出所有1000---2000年之间的闰年\n请输入:");
	scanf("%d",&judge);
	if(judge == 1)
	{
		int year;
		printf("请输入年份: ");
		scanf("%d",&year);
		if(judge_leap_year(year))
			printf("%d年是闰年!\n",year);
		else 
			printf("%d年不是闰年!\n",year); 
	}
	if(judge == 2)
	{
		int count = 0;
		printf("1000---2000年内,以下年份是闰年:\n");
		for(int i = 1000 ; i <= 2000 ; i++)
			if(judge_leap_year(i))
			{
				printf("%d\t",i);
				count++;
				if(count == 10)
				{
					printf("\n");
					count = 0;
				}
			}
	}
	printf("\n");
	exit(0);
}
