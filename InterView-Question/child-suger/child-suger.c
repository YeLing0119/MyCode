#include <stdio.h>
#include <stdlib.h>

void SwapNum(int *arr , int i , int j)
{ 
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void Sort(int *ch , int len)
{
	for(int i = 0 ; i < len - 1 ; i++)
	{	
		for(int j = 0 ; j < len - i -1; j++)
		{
			if(ch[j]>ch[j+1])
			{
				SwapNum(ch, j, j+1);
			}
		}
	}
}

void PrintArr(int *arr, int len)
{
	int i=0;
	for(; i<len; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

int main()
{
	int child[]={5,10,2,9,15,9};
	int suger[]={6,1,20,3,8};
	int len_child = sizeof(child) / sizeof(child[0]);
	int len_suger = sizeof(suger) / sizeof(suger[0]);
	int count_child = 0;  // 得到需求得到满足的孩子的个数
	int count_suger = 0;  // 糖果指针 
	printf("%d %d\n", len_child, len_suger);	
	PrintArr(child, len_child);
	PrintArr(suger, len_suger);
	Sort(child, len_child);
 	Sort(suger, len_suger);
	PrintArr(child, len_child);
	PrintArr(suger, len_suger);
	while(count_child < len_child && count_suger < len_suger)
	{
		
		printf("第%d个孩子:需求%d --> 第 %d个糖果:大小%d\n", count_child, 
				child[count_child],count_suger, suger[count_suger]);
		
		if(child[count_child] < suger[count_suger])
		{	
			// 如果孩子的需求能够满足,则下一个孩子,下一个糖果
			count_child++;
			count_suger++;
		}
		else 
		{
			// 如果孩子的需求不能满足，则就下一个糖果
			count_suger++;	
		}
	}
	printf("这些糖果能够满足%d个孩子\n",count_child);
	exit(0);
}
