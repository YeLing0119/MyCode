#include <stdio.h>
#include <stdlib.h>

int IsLeapYear(int year){
	if((year%4 == 0 && year%100 != 100 ) || year % 400 == 0){
		return 1;
	}
	return 0;
}

int main(){
	int year = 0;
	printf("please enter year : ");
	scanf("%d", &year);
	if(IsLeapYear(year)){
		printf("%d is leap year \n", year);
	}else{
		printf("%d isn't leap yaer \n", year);
	}
	exit(0);
}
