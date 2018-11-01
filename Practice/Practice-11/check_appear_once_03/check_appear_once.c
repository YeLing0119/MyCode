#include <stdio.h>

int main(){
	printf("****Check Appear Once****\n");
	int arr[] = {11,22,33,44,55,66,66,55,44,33,22,11,65};
	int strlen_arr = sizeof(arr)/sizeof(arr[0]);
	int arr_temp = arr[0];
	for (int i = 1 ; i < strlen_arr ; i++){
		arr_temp ^= arr[i]; 
	}
	printf("The number that appear once is %d \n", arr_temp);
	return 0;
} 
