#include <stdio.h>
#include <stdlib.h>

int HowJuiceDrink(int drink_num , int swap_num){
	int total_drink = drink_num ; 
	int juice = drink_num;	//刚买来时
	int bottle = drink_num; //买来喝完的瓶子
	int remainder = 0;		//上次兑换之后手里还剩空瓶数 只可能是小于swap_num
	printf("****** total_drink = %d  juice = %d bottle = %d remainder = %d \n",
			total_drink , juice , bottle , remainder);
	while(bottle + remainder > 1){
		bottle = bottle + remainder ;
		remainder = bottle % swap_num;
		juice = bottle / swap_num;
		total_drink += juice;
		bottle = juice;
		printf("------ total_drink = %d  juice = %d bottle = %d remainder = %d \n",
				total_drink , juice , bottle , remainder);
	}
	return total_drink ;
}

int main(){
	int drink_num = 0;
	int final_drink;
	int swap_num = 0;
	printf("请输入喝了多少瓶汽水，以及几个空瓶换一瓶饮料:\n");
	scanf("%d %d" , &drink_num , &swap_num);
	fflush(stdin);
	printf("输入检测 : %d %d\n" , drink_num , swap_num);
	final_drink = HowJuiceDrink(drink_num, swap_num);
	printf("最终喝了%d瓶饮料\n", final_drink );
	exit(0);
}
