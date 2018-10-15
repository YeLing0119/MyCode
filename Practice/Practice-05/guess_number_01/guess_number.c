#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GuessNum(){
	srand((int)time(0));
	int rand_num = rand() % 101;
	int user_num = 0 ;
	
	while(1){
		printf("请输入你猜的数字\n");
		scanf("%d",&user_num);
		if(user_num > 100 || user_num < 0)
			printf("你输入的数字有误!");
		
		if(user_num > rand_num){
			printf("你猜的大了!\n");
		}else if(user_num < rand_num){
			printf("你猜的小了!\n");
		}else{
			printf("恭喜你，你猜对了!\n");
			break;
		}
	}
}

void PrintMeun(){
	printf("**********************************\n");
	printf("***       1、 开始游戏         ***\n");
	printf("***       2、 结束游戏         ***\n");
	printf("**********************************\n");
	printf("请输入你的选项:");
}


int main(){
	while(1){
		int switch_num = 0 ;
		PrintMeun();
		scanf("%d",&switch_num);
		if(switch_num == 1)
			GuessNum();
		else if (switch_num == 2){
			printf("结束游戏!"),exit(0);
		}else{
			printf("你的输入有误，请重新输入!\n");
		}
	}
	exit(0);
}
