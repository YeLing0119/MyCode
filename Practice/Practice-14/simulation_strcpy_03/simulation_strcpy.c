#include <stdio.h>
#include <stdlib.h>

char *SimStrcpy(char *strDestination ,const char *strSource){
	char *temp = strDestination;
	while((*strDestination++ = *strSource++) != '\0');
	return temp;
}

int main(){
	char src[25] = "I LOVE CHINA!";
	char dst[25] = { 0 };
	char *ectype = NULL;
	ectype = SimStrcpy(dst, src);
	printf("%s\n", dst);
	printf("%s\n", ectype);
	exit(0);
}
