#include <stdio.h>
#include <stdlib.h>

int main(){
	int input_char = 0 ; 
	printf("请输入:\n");
	while((input_char = getchar())!= EOF){
		if(input_char == '\n'){
			printf("\n");
		}	
	
		if(input_char >= 97 && input_char <= 122){
			printf("%c ", input_char - 32);
		}
			
		if(input_char >= 65 && input_char <= 90){
			printf("%c ",input_char + 32);
		}
	
		if(input_char >= 48 && input_char >= 57){
			//printf("输出:%c\n",input_char);
		}
	}
	exit(0);
}
