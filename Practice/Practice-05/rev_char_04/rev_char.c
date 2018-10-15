#include <stdio.h>
#include <stdlib.h>

int main(){
	while(1){
		char input_char;
		printf("请输入:");
		scanf("%c", &input_char);
		
		if(input_char >= 97 && input_char <= 122){
			printf("输出:%c\n", input_char - 32);
		}
			
		if(input_char >= 65 && input_char <= 90){
			printf("输出:%c\n",input_char + 32);
		}
	
		if(input_char >= 48 && input_char >= 57){
			//printf("输出:%c\n",input_char);
		}
	}
	exit(0);
}
