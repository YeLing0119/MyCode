#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int LeftCircle(char *_arr_, int _k_, int len){
	if(_arr_ == NULL && _k_ > 0){
		return -1;
	}
	//printf("Len = %d \n", len);
	int i = 0;
	int real_len = _k_ % len;	//计算出真正左旋位数
	
	//printf("real_len = %d \n", real_len);

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

int main(){
	int num_char = 0;
	char Arr[1024] = {0};
	printf("请输入一个字符串：");
	scanf("%s", Arr);
	printf("请输入左旋多少个字符：");
	scanf("%d" , &num_char);
	LeftCircle(Arr, num_char, strlen(Arr));
	printf("左旋%d位后为:%s\n", num_char, Arr);
	exit(0);
}


