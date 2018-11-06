#include <stdio.h>
#include <stdlib.h>

void* SimMemcpy(void *dest , const void *src , unsigned int size){
	if(dest == NULL && src == NULL){
		return NULL;
	}
	char *dest_temp  = (char *)dest;
	char *src_temp = (char *)src;
	while(size--){
		*dest_temp = *src_temp;
		dest_temp++,src_temp++;
	}
	return dest;
}

int main(){
	
	printf("String SimMemcpy : \n");
	char str1[] = "this is a test";
	char buff[20] = {0};
	if(SimMemcpy(buff , str1, sizeof(str1))){
		printf("String : %s\n" , buff);
	}
	
	printf("Int SimMemcpy : \n");
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	int buff2[20] = {0};
	if(SimMemcpy(buff2 , arr , sizeof(arr))){	
		int i = 0;
		printf("Int : ");
		for(; i < sizeof(arr)/sizeof(arr[0]); i++){
			printf("%d  " , buff2[i]);
		}
		printf("\n");
	}
}
