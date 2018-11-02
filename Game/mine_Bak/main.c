#include "mine.h"

void menu(){
	system("clear");
	printf("******************************\n");
	printf("*****     1、闯关模式    *****\n");
	printf("*****     2、自定义模式  *****\n");
	printf("*****     3、退出        *****\n");
	printf("******************************\n");
	printf("请输入选项<1/2>:");
}

int main(){
	int select = 0;
	menu();
	scanf("%d", &select);
	switch (select){
		case 1: PassMode();
			break;
		case 2: CustomMode();
			break;
		case 3: exit(0);
			break;
		default:
			break;
	}
	return 0;
}
