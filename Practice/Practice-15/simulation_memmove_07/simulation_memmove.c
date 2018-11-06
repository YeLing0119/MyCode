#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* SimMemmove(void *dest , const void *src , unsigned int size){
	char *dest_temp = (char *)dest;
	char *src_temp = (char *)src;
	if(dest >  src && dest < src + size){
		dest_temp = (char *)dest + size - 1;
		src_temp = (char *)src + size - 1;
		while(size--){
			*dest_temp-- = *src_temp--;
		}
	}else{	
		while(size--){
			*dest_temp++ = *src_temp++;
		}
	}
	return dest;
}

int main(){
	char str[20] = "abcdefg1234567";
	printf("Bofore Move : ");
	printf("%s\n" , str);
	SimMemmove(str + 1, str, strlen(str));
	printf("After  Move : ");
	printf("%s\n" ,str);
}
