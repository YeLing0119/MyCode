#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//	Way1
int  CountOneBitWay1(int number){
	//printf("%x\n",number);
	int count = 0;
	while(number){
		if(number%2 == 1){
			count++;
		}
		number = number/2;
	}
	return count;
}

//Way2

int CountOneBitWay2(int number){
	int count = 0;
	int i = 0;
	for( i = 0; i < 32 ; i++){
		if((number >> i) & 1 ==1 ){
			count++;
		}
	}
	return count;
}

//Way3
int CountOneBitWay3(int number){
	int count = 0;
	while(number){
		count++;
		number = number & (number - 1);
	}	
	return count;
}

int main(){
	int number = 0;
	printf("please enter a number:\n");
	scanf("%d",&number);
	//way1 - mod 
	printf("Way1 : contain one : %d\n",CountOneBitWay1(number));
	//Way2 - shift function
	printf("Way2 : contain one : %d\n",CountOneBitWay2(number));
	//Way3 - sub one
	printf("Way3 : contain one : %d\n",CountOneBitWay3(number));
}
