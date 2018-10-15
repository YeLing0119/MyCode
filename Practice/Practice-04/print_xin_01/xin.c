#include <stdio.h>
#include <stdlib.h>

void PrintLine(int xin_num){
	for(int i = 0 ; i < xin_num ; i++){
		printf("*");
	}
	printf("\n");
}

void PrintXin(int len){
	for(int line_xin = 1 ; line_xin <= len ; line_xin += 2){
		PrintLine(line_xin);
	}
	for(int line_xin = len - 2 ; line_xin >= 1 ; line_xin -=2){
		PrintLine(line_xin);
	} 
}

int main(){
	int len = 0 ;
	printf("请输入中间行星号的个数！(个数应为奇数且大于0)\n");
	scanf("%d",&len);
	if(!(len%2))printf("输入有误！\n"),exit(0);
	PrintXin(len);
	exit(0);
}
