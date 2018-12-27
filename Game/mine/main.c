#include "mine.h"

void menu(){
	system("clear");
	printf("******************************\n");
	printf("*****      1、扫雷       *****\n");
	printf("*****      2、退出       *****\n");
	printf("******************************\n");
	printf("请输入选项<1/2>:");
}

int main(){
	int select = 0;
	char string[1024];
	menu();
	ss:scanf("%d", &select);
	gets(string);
	switch (select){
		case 1: Mine();
			break;
		case 2:exit(0);
			break;
		default:
			{
				printf("输入错误，重新输入 \n");
				goto ss;
			}		
	}
	return 0;
}
