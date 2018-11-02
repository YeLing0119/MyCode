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

#if 0
unsigned int ReverseBit(unsigned int number){
	int ret = 0;
	int i = 0;
	for(i = 0 ; i < 32 ; i++){
		ret <<= 1 ;
		
		if(number & 0x01){
			ret |= 1;
		}

		number >>= 1;
	}
	return ret;
}
#endif

int main(){
	printf("*****reverse bit*****\n");
	unsigned int number = 0;
	unsigned int result = 0;
	printf("please enter a number !\n");
	scanf("%d",&number);
	result = ReverseBit(number);
	printf("result = %u", result);
	return 0;
}
