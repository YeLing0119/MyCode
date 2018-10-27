#include <stdio.h>
#include <stdlib.h>

void PrintMulTable(int line){
	int i,j;
	for(i = 1 ; i <= line ; i++){
		for(j = 1 ; j <= i ; j++){
			printf("%d*%d=%d\t", i, j, i*j);
		}
		printf("\n");
	}
}

int main(){
	int line = 0; 
	printf("please enter how many you want watch:");
	scanf("%d", &line);
	PrintMulTable(line);
	exit(0);
}
