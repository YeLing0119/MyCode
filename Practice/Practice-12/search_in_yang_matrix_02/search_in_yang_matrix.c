#include <stdio.h>
#include <stdlib.h>

int  SearchMatrix(int (*_arr_)[3], int _row_, int _col_, int _data_){
	if(_arr_ == NULL){
		printf("_arr_  error!\n");
		return -1;
	}
	int row = 0;
	int col = _col_ - 1;
	while(row < _row_ && col >= 0){
		if(_arr_[row][col] == _data_){
			return 1;
		}else if(_arr_[row][col] > _data_){
			col--;
		}else{
			row++;
		}
	}
	return 0;
}

int main(){
	int data = 0;
	int result = 0;
	int arr[3][3] = {{1,2,3},{2,3,4},{3,4,5}};
	printf("请输入要查找的数字：");
	scanf("%d", &data);
	result = SearchMatrix(arr, 3, 3, data);
	if(result == 1){
		printf("找到了!\n");
	}else if(result == 0){
		printf("没有找到!\n");
	}else{
		printf("error!\n");
	}
	exit(0);
}
