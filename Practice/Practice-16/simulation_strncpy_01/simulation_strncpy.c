#include <stdio.h>
#include <stdlib.h>

char* SimStrncpy(char* dst , char* src, int num){
	char* dst_temp = dst;
	int num_temp = num;
	if(dst == NULL && src == NULL){
		return NULL;
	}
	for( ; num > 0 ; num--){
		*dst++ = *src++;
	}
	return dst;
}

int main(){
	char str[] = "this is a test!";
	char buff[10];
	if(SimStrncpy(buff, str, 4)){
		printf("%s", buff);
	}
	exit(0);
}
