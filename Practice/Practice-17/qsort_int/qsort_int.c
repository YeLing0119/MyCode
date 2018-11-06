#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *x ,const  void *y){
	int *_x_ = (int *)x;
	int *_y_ = (int *)y;
	
	if(*_x_ > *_y_){
		return 1;
	}else if(*_x_ > *_y_){
		return -1;
	}else{
		return 0;
	}
}

void PrintArr(const int *Arr , int len){
	int i = 0;
	for( ; i<len ; i++){
		printf("%d ", Arr[i]);
	}
	printf("\n");
}

int main(){
	int Arr[10] = {11,22,55,66,44,22,33,77,88,11};
	printf("Before Qsort:\n");
	PrintArr(Arr,sizeof(Arr)/sizeof(Arr[0]));
	qsort(Arr, 10 ,4, cmp_int);
	printf("After Qsort:\n");
	PrintArr(Arr,sizeof(Arr)/sizeof(Arr[0]));
	exit(0);	
}
