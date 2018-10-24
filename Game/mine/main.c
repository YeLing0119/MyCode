#include "mine.h"

void menu(){
	printf("******************************\n");
	printf("*****      1、扫雷       *****\n");
	printf("*****      2、退出       *****\n");
	printf("******************************\n");
	printf("请输入选项<1/2>:");
}

int main(){
	int select = 0;
	menu();
	scanf("%d", &select);
	switch (select){
		case 1: Mine();
			break;
		case 2:exit(0);
			break;
		default:
			break;
	}
	system("pause");
	return 0;
}