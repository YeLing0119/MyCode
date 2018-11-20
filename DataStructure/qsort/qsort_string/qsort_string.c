#include <stdio.h>
#include <stdlib.h>

int cmp_string(const void* elem1 , const void *elem2){
	int ret  = 0 ; 
	while(!(ret = *((char*)elem1++) - *((char*)elem2++)) && *(char*)elem1);
	return -ret;
}

int main(){
	int i = 0;
	char str[][10] = {"abcd" , "abcD" , "Abcd" , "aBcd" , "aBCd"};

	printf("Before : ");
	for(i = 0 ; i < 5 ; i++){
		printf("%s  ", str[i]);
	}
	printf("\n");

	qsort(str , 5 , 10 , cmp_string);

	printf("After  : ");
	for(i = 0 ; i < 5 ; i++){
		printf("%s  ", str[i]);
	}
	printf("\n");
}
