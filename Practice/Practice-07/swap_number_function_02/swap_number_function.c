#include <stdio.h>
#include <stdlib.h>

void SwapNumber(int* first, int* second){
	*first = *first ^ *second;
	*second = *first ^ *second;
	*first = *first ^ *second;
}

int main(){
	int number1,number2;
	printf("please enter two number : ");
	scanf("%d %d", &number1, &number2);
	printf("Before : %d  %d \n", number1, number2);
	SwapNumber(&number1, &number2);
	printf("After : %d  %d \n", number1, number2);
	exit(0);
}
