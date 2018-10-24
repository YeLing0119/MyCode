#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//	Way1
void  CountOneBitWay1(int number){
	//printf("%x\n",number);
	int count = 0;
	while(number){
		if(number%2 == 1){
			count++;
		}
		number = number/2;
	}
	printf("Way1 : contain one : %d\n", count);
}

//Way2

void CountOneBitWay2(int number){
	int count = 0;
	int i = 0;
	for( i = 0; i < 32 ; i++){
		if((number >> i) & 1 ==1 ){
			count++;
		}
	}
	printf("Way2 : contain one : %d\n", count);
}

//Way3
void CountOneBitWay3(int number){
	int count = 0;
	while(number){
		count++;
		number = number & (number - 1);
	}	
	printf("Way3 : contain one : %d\n", count);
}
int main(){
	int number = 0;
	printf("please enter a number:\n");
	scanf("%d",&number);
	//way1 - mod 
	CountOneBitWay1(number);
	//Way2 - shift function
	CountOneBitWay2(number);
	//Way3 - sub one
	CountOneBitWay3(number);
}
