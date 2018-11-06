#include <stdio.h>
#include <stdlib.h>

int first_appear = -1;

int SimStrchr(char* str , char charset){
	char* str_temp = str;
	if(str == NULL){
		return 2;
	}
	while(*str_temp != charset){
		if(*str_temp == '\0'){
			return 1;
		}
		str_temp++;
	}
	first_appear = str_temp - str + 1;
	return 0;
}

int main(){
	char Arr[] = "This is a test string!";
	char charset = '0';
	char *Error[] = {"Find It!", "Not Find!", "Ptr Error!"};
	printf("Original String : %s \n" , Arr);
	printf("Find  Character :");
	scanf("%c" , &charset);
	printf("Result : %s\n",Error[SimStrchr(Arr , charset)]);
	printf("First Appear Location : %d\n" , first_appear);
	exit(0);
}
