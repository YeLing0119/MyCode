#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrimeNumber(int number){
	int count = 0;
	float max_count = (int)sqrt(number);
	for(count = 2 ; count <= max_count ; count++){
		if(number % count == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int number = 0;
	printf("please enter a number : ");
	scanf("%d", &number);
	if(IsPrimeNumber(number)){
		printf("%d is prime \n", number);
	}else{
		printf("%d isn't prime \n", number);
	}
}
