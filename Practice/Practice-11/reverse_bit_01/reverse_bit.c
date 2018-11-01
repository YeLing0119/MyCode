#include <stdio.h>

unsigned int ReverseBit(unsigned int number){
	unsigned int  data = 0;
	int num = sizeof(int)* 8;//求整型的比特位，在这里为32
	int i = 0;
	while (i < num){
		if ((number >> i) & 1){
			data |= 1 << (31-i);
		}
		i++;
	}
	return data;
}


int main(){
	printf("*****reverse bit*****\n");
	unsigned int number = 0;
	unsigned int result = 0;
	printf("please enter a number !\n");
	scanf("%d",&number);
	result = ReverseBit(number);
	printf("result = %d", result);
	return 0;
}
