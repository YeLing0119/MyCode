#include<stdio.h>
#include<stdlib.h>

int main()
{
	int number1,number2;
	int max_common=1;
	printf("请输入要求的数字：");
	scanf("%d %d",&number1,&number2);
	for(int i = 2 ; i < number1; i++)
	{	
		if(number1 % i == 0 || number2 % i == 0)
		{
			max_common *= i ;
		}
	}
	printf("最大公约数为%d\n" , max_common);
	exit(0);
}
