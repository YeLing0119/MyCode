#include <stdio.h>
#include <stdlib.h>


int SimStrcmp(const char *str1 , const char *str2){
	int  ret = 0;
	if(str1 == NULL || str2 == NULL){
		return 2;
	}
	while(!(ret = *str1 - *str2) && *str1){
		str1++,str2++;
	}
	
	if(ret > 0){
		return 1;
	}else if(ret < 0){
		return -1;
	}else{
		return 0;
	}
}

int main(){
	char str1[50];
	char str2[50];
	char *PrintArr[] = {"str1 < str 2" , "str1 = str2", "str1 > str2" , "Ptr Error"};
	printf("Please Enter First String :");
	scanf("%s" , str1);
	printf("Please Enter Second String :");
	scanf("%s" , str2);
	printf("Result : %s \n",PrintArr[SimStrcmp(str1 , str2) + 1]);
} 
