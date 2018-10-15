#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char password_real[] = "I_love_China";

int Input(){
	char password_usr[20] = {0};
	printf("请输入密码！\n");
	scanf("%s",password_usr);
	if(strcmp(password_usr,password_real) == 0)
		return 1;
	return 0;
}

int main(){
	int count = 0;
	while(1){
		if( count > 2){
			printf("密码连续输错三次，退出！");
			break;
		}else if(Input()){
			printf("登陆正确!\n");
			break ;
		}else{
			printf("密码输入错误！\n");
			++count;
		}
	}
	exit(0);
}
