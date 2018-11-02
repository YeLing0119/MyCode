#include <stdio.h>


int count_average(int number1 , int number2){
	return (number1&number2) + ((number1^number2)>>1);
}

#if 0
int count_average(int number1 , int number2){
	//if(number1 >= number2){
		return number2 + ((number1 - number2) >> 1);
	//}else{
	//	return number1 + ((number2 - number1) >> 1);	
	//}
}
#endif

int main(){
	int a = 310;
	int b = 210;
	int result = 0;
	result = count_average(a,b);
	printf("Average = %d\n", result);
	result = count_average(b,a);
	printf("Average = %d\n", result);
	return 0;
}
