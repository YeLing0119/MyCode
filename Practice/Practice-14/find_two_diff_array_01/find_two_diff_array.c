#include <stdio.h>
#include <stdlib.h>

//定义一个结构体用于返回两个值
typedef struct Diff{
	int first_diff ;
	int second_diff ;
}Diff_t;

//把给定缓冲区中，从start位置到end位置的数组全部异或
int PositionXor(int *arr , int start , int end){
	int xor_result = 0;
	for(;start <= end; start++){
		xor_result ^= arr[start];
	}
	return xor_result;
}

//检查数字的二进制中第几位为第一次给定的数字
int CheakBinaryBit(int number , int data){
	int result = 0;
	int i = 0;
	for(i = 0 ; i < 32 ; i++){
		if(number & 0x01 == data){
			result++;
			return result;
		}
		number >>= 1;
	}
	return -1;
}

//检查数字二进制位中指定位是否为data
int CheakAppointBit(int number , int bit_num , int data){
	number >>= bit_num - 1;
	if(number & 0x01 == data){
		return 1;
	}
	return 0;
}

//寻找数组中只出现一次的两个数据
Diff_t FindTwoDiff(int *arr, int len){
	int count = 0 ;
	Diff_t diff = {-1,-1}; 
	int left_arr[10];
	int right_arr[10];
	int left_point = 0;
	int right_point = 0;
	//1.第一次异或，整体异或
	int first_result = PositionXor(arr, 0 , len - 1);
	//2.拆分数组
	int first_one = CheakBinaryBit(first_result , 1);
	if(first_one == -1){
		printf("位检测失败 : 不存在给定的数据\n");
		return diff; 
	}
	for(count = 0 ; count < len ; count++){
		if(CheakAppointBit(arr[count], first_one, 1)){
			left_arr[left_point] = arr[count];
			left_point++;
		}else{
			right_arr[right_point] = arr[count];
			right_point++;
		}	
	}
	//3.对拆分后的数组进行异或
	diff.first_diff = PositionXor(left_arr , 0 , left_point - 1);
	diff.second_diff = PositionXor(right_arr , 0 , right_point - 1);
	
	return diff;
}

int main(){
	int arr[] = { 11 , 22 ,11 , 44 , 33 , 66 , 44 , 55 , 22 , 33};
	Diff_t diff = FindTwoDiff(arr, sizeof(arr)/sizeof(arr[0]));
	printf("Two Different Number : %d %d \n" , diff.first_diff , diff.second_diff);
	//printf("%d", CheakBinaryBit(1,1));
	//printf("%d\n", PositionXor(arr, 0 , 2));
	//printf("%d\n" , CheakAppointBit(2 ,2 ,1));
	exit(0);
}
