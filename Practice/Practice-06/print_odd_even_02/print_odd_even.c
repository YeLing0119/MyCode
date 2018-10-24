#include <stdio.h>
#include <stdlib.h>

//	same as first question 
//	just storage the flag into array

void CountOddEven(int number){
	int ch[32] = { 0 };
	int i = 0;
	
	for(i = 0 ; i < 32; i++){
		if(number % 2 == 1){
			ch[i] = 1;
		}
		number = number / 2;
	}

	//printf("Origin : \n");
	//for(i = 0 ; i < 32; i++){
	//	printf("%d  ", ch[i]);
	//}
		
	printf("\nOdd : \n");
	for(i = 1 ; i < 32 ; i += 2){
		printf("%d  ", ch[i]);
	}

	printf("\nEven : \n");
	for(i = 0 ; i < 32 ; i += 2){
		printf("%d  ", ch[i]);
	}
	printf("\n");
}

int main(){
	int number = 0;
	printf("please enter a number:\n");
	scanf("%d", &number);
	CountOddEven(number);
	exit(0);
}
