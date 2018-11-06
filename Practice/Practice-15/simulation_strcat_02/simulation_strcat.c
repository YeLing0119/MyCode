#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#if 0
//直接加上字符串长度
char *SimStrcat(char *strDestination , const char *strSource){
	assert(strDestination);
	assert(strSource);
	int len = strlen(strDestination);
	char *strTemp = strDestination;
	while((*((strDestination++) + len) = *strSource++) != '\0');
	return strTemp;
}
#endif


//直接找到strDestination的\0
char *SimStrcat(char *strDestination , const char *strSource){
	assert(strDestination);
	assert(strSource);
	char *strTemp = strDestination;
	while(*strDestination != '\0'){
		strDestination++;
	}
	while((*strDestination++ = *strSource++) != '\0');
	return strTemp;
}

int main(){
	char str1[] = "I LOVE ";
	char str2[] = "CHINA";
	SimStrcat(str1, str2);
	printf("%s\n", str1);
	exit(0);
}
