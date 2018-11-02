#include <stdio.h>

void Swap(char *_arr_, int _x_, int _y_){
	int tmp = _arr_[_x_];
	_arr_[_x_] = _arr_[_y_];
	_arr_[_y_] = tmp;
}

void ReverseString(char* _arr_ , int _start_ , int _end_){
	int start = _start_;
	int end = _end_;
	while(start < end){
		Swap(_arr_, start, end);
		start++;
		end--;
	}
}

int main(){
	int word_start = 0;
	int word_end = 0;
	char arr[] = "student a not am i";
	int len = sizeof(arr)/sizeof(arr[0]) - 1;
	printf("%s\n",arr);
	ReverseString(arr,0,len - 1);
	printf("%s\n",arr);
	while(arr[word_end] != '\0'){
		if(arr[word_end] == ' '){
			ReverseString(arr, word_start,word_end - 1);
			word_start = word_end + 1;
		}
		if(arr[word_end + 1] == '\0'){
			ReverseString(arr, word_start, word_end);
		}
		word_end++;
	}
	printf("%s\n",arr);
	return 0;
}
