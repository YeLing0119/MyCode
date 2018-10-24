#include <stdio.h>
#include <stdlib.h>

//	This question have two ways to solve 

//1. use recurrence  使用递归

void ReEveryBit(int number){
	if(number > 9){
		ReEveryBit(number / 10);
	}
	printf("%d  ", number%10);
}
 
//2. use iteration	使用迭代

void ItEveryBit(int number){
	int ch[20];
	int i = 0;
	int count = 0 ;
	while(number){
		ch[count] = number%10;
		number = number / 10;
		count++;		
	}

	for ( i = count - 1 ; i >= 0 ; i--){
		printf("%d  ", ch[i]);
	}
}

int main(){
	
	int number = 0;
	printf("please enter a number :\n");
	scanf("%d", &number);
	printf("Use Resurrence : \n");
	ReEveryBit(number);
	printf("\n");
	printf("Use Iteration : \n");
	ItEveryBit(number);
	printf("\n");
	exit(0);
}
