#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* SimStrncat(char *dst , char *src , int num){
	char* dst_temp = dst;
	int len = strlen(dst);
	dst = dst + len;
	if(dst == NULL || src == NULL){
		return NULL;
	}
	for( ; num > 0 ; num--){
		*dst++ = *src++;
	}
	return dst_temp;
}

int main(){
	char str[25] = "this is a test!";
	char buff[25] = "this test!";
	SimStrncat(buff , str , 5);
	printf("%s", buff);
	exit(0);
}
