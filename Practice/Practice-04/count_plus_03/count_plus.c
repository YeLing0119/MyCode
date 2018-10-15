#include <stdio.h>
#include <stdlib.h>

int PruduceNum(int num , int count){
	int produce_num = num;
	for( int i = 1 ; i < count ; i ++){
		if( count == 1 ){
			printf("%d \n", produce_num);
			return produce_num ;
		}
		produce_num *=10;
		produce_num += num;
	}
	return produce_num;
}

int main(){
	int num = 0 , count = 0;
	int result = 0;
	printf("请输入要连加的数字，及加多少次！\n");
	scanf("%d %d" , &num , &count);
	if(num > 10 || num < 0 ){
		printf("输入错误!");
	}
	for(int i = 1 ; i <= count ; i ++){
		result += PruduceNum( num , i );
	}
	printf("result : %d\n" , result);
	exit(0);
}
