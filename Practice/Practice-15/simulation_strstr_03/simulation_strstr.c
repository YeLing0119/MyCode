#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* SimStrstr(char *str1 , char *str2){
	char *str1_temp1 = str1;
	char *str1_temp2 = str1;
	char *str2_temp = str2;
	char *Error[3] = {"Not Find", "Ptr Error" , "Empty StringSet"};
	if(str1 == NULL || str2 == NULL){
		return Error[1]; 
	}
	if(!strlen(str2)){
		return Error[2];
	}
	while(*str1_temp1){
		str1_temp2 = str1_temp1;
		while(*str1_temp2 == *str2_temp){
			str1_temp2++,str2_temp++;
			if(*str2_temp == '\0'){
				return str1_temp1;
			}
		}
		str2_temp = str2;
		str1_temp1++;
	}
	return Error[0];
}

int main(){
	char arr1[] = "abcdabc1234def";
	char arr2[] = "bc12";
	printf("Search String : %s\n" , arr1);
	printf("Search Result : %s\n",SimStrstr(arr1, arr2)); 
}


