#include <stdio.h>
#include <stdlib.h>

int CountOneBit(int number){
	int count = 0;
	while(number){
		count++;
		number = number & (number - 1);
	}
	return count;
}

void FindDiffBit(int number1, int number2){
	int diff_number = 0;
	diff_number = CountOneBit(number1^number2);
	printf("Two number have %d different !\n", diff_number);
}

int main(){
	int number1 = 0;
	int number2 = 0;
	printf("please enter two number : ");
	scanf("%d %d", &number1, &number2);
	FindDiffBit(number1, number2);
	exit(0);
}
