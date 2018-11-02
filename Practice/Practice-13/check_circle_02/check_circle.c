#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int LeftCircle(char *_arr_, int _k_, int len){
	if(_arr_ == NULL && _k_ > 0){
		return -1;
	}
	int i = 0;
	int real_len = _k_ % len;	//计算出真正左旋位数
	for(i = 0; i < real_len; i++){
		int j = 0;
		char tmp = _arr_[0];
		for(; j < len - 1 ; j++){
			_arr_[j] = _arr_[j + 1];
		}
		_arr_[j] = tmp;
	}
	return 0;
}

int CheckCircle(char *Arr1 , char *Arr2, int len){
	int i = 0;
	for(; i < len ; i++){
		LeftCircle(Arr2, i, len);
		if(strcmp(Arr1, Arr2) == 0){
			return 1;
		}	
	}	
	return 0;
}

int main(){
	char Arr1[] = {0};
	char Arr2[] = {0};
	int result = 0;
	printf("请输入字符串一:");
	scanf("%s", Arr1);
	printf("请输入字符串二:");
	scanf("%s", Arr2);
	
	result = CheckCircle(Arr1, Arr2, strlen(Arr1));
	
	if(result == 1){
		printf("是\n");
	}else{
		printf("否\n");
	}
	
	exit(0);
}
