#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 10

// init -- let all element is '0' -> '0' + ARRAY_MAX_SIZE
void init(char *Arr, int _size){
	int i;
	for(i = 0 ; i < _size ; i++){
		Arr[i] = '0' + i;
	}
}

// empty -- let  all element is '0'
void empty(char *Arr, int _size){
	int i,j;
	for(i = 0 ; i < _size ; i++){
		Arr[i] = '0';
	}	
}

void SwapChar(char* x, char* y){
	char tmp = *x;
	*x = *y;
	*y = tmp;
}

void reverse(char *Arr, int _size){
	int left = 0 ;
	int right = _size - 1;
	while(left <= right){
		SwapChar(&Arr[left], &Arr[right]);
		left++;
		right--;
	}
}

void PrintArray(char *Arr, int _size){
	int i = 0;
	for(; i < _size; i++){
		printf("%c  ", Arr[i]);
	}
	printf("\n");
}

int main(){
	char Arr[ARRAY_MAX_SIZE];
	init(Arr, ARRAY_MAX_SIZE);
	printf("After Init :");
	PrintArray(Arr,ARRAY_MAX_SIZE);
	reverse(Arr, ARRAY_MAX_SIZE);
	printf("After Reverse :");
	PrintArray(Arr,ARRAY_MAX_SIZE);
	empty(Arr, ARRAY_MAX_SIZE);
	printf("After Empty :");
	PrintArray(Arr,ARRAY_MAX_SIZE);
	exit(0);
}
