#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsShuixianhua(int num){
	//分别取出个位、十位、百位
	int arr[3] = {0} ;
	int num_bak = num ;
	//倒着存，跟直观的进行处理
	for(int count = 2 ; count >= 0 ; count --){
		arr[count] = num % 10;
		num = num / 10 ;
	}

	if( num_bak == pow(arr[0],3) + pow(arr[1], 3) + pow(arr[2], 3) ) 
		return 1 ;
}

int main(){
	//水仙花数是三位数，所以从100开始
	for(int count = 100 ; count <= 999 ; count++){
		if(IsShuixianhua(count))
			printf("%d\t", count);
	}
}
