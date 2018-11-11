#include <stdio.h>
#include <stdlib.h>

int SimStrncmp(char *str1 , char *str2 , int num){
	for( ; num > 0 ; num--){
		//printf("str1 = %c  str2 = %c  num = %d\n" , *str1 , *str2 , num);
		if(*str1 > *str2){
			return 1;
		}else if(*str1 < *str2){
			return -1;
		}
		str1++,str2++;
	}
	return 0;
}

int main(){
	char str1[] = "this Is a test!";
	char str2[] = "this is a test!";
	
	printf("%d\n", SimStrncmp(str1 , str2 , 8));
	exit(0);
}
