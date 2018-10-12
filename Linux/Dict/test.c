#include <stdio.h>
#include <string.h>

int main()
{
	if(strcmp("center","cent")>0){
		printf("1");
	}else if(strcmp("center","cent") == 0){
		printf("0");
	}else{
		printf("-1");
	}
}
