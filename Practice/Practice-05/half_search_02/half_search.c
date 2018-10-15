#include <stdio.h>
#include <stdlib.h>

int HalfSearch(const int *arr,const int buffer, int count){
	int left = 0;
	int right = count - 1;
	
	while(left <= right){
	
		int mid = left + (right - left) / 2;
	
		if(arr[mid] == buffer){
			return mid;
		}else if(arr[mid] > buffer){
			right = mid - 1;
		}else{
			left  = mid + 1 ;
		}
	}
	return -1;
}



int main(){
	int number = 0 ;
	int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	
	printf("请输入你要查找的数!\n");
	scanf("%d",&number);
	int result_status = HalfSearch(arr, number, sizeof(arr)/sizeof(arr[0]));
	if(result_status == -1){
		printf("-1 :没有找到!\n");
	}else{
		printf("找到了，下标是%d\n", result_status);
	}
	exit(0);
}
