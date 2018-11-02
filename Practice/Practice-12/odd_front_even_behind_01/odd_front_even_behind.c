#include <stdio.h>

void PrintArr(int *_arr_, int _len_){
	int i = 0;
	for(i = 0; i < _len_ ; i++){
		printf("%d  ", _arr_[i]);
	}
	printf("\n");
}

void Swap(int *_arr_, int _x_, int _y_){
	int tmp = _arr_[_x_];
	_arr_[_x_] = _arr_[_y_];
	_arr_[_y_] = tmp;
}

void OddEven(int *_arr_ , int _len_){
	int first = 0;
	int last = _len_ -1;
	printf("Odd - Even\n");
	while(first < last){
	   	//PrintArr(_arr_, _len_);
		if(_arr_[first] % 2 == 0 && _arr_[last] % 2 == 1){
			Swap(_arr_, first, last);
		}
		first++;
		last--;
	}
}

int main(){
	int arr[] = {22, 55, 11, 33, 66, 88, 44, 42, 12, 56, 87};
	int arr_len  = sizeof(arr)/sizeof(arr[0]);
	printf("Before:\n");
	PrintArr(arr,arr_len);

	OddEven(arr,arr_len);

	printf("After:\n");
	PrintArr(arr,arr_len);
	return 0;
}
