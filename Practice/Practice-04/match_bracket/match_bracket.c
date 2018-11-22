#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack_point = 0;
char stack_bracket[100];

void push(char buff)
{
	stack_bracket[stack_point] = buff;
	stack_point++;
}

void pop()
{
	stack_point--;
}

void cheak()
{
	if (stack_bracket[stack_point - 1] == '}'||stack_bracket[stack_point - 2] == '{'){
		pop(); pop();
	}

	if (stack_bracket[stack_point - 1] == ')'||stack_bracket[stack_point - 2] == '('){
		pop(); pop();
	}

	if (stack_bracket[stack_point - 1] == ']'||stack_bracket[stack_point - 2] == '['){
		pop(); pop();
	}
}

int main(){
	char code[10240] = { 0 };
	int count = 0;	//记录现在一共有多少个字符
	printf("**************************************\n");
	printf("*****  欢迎使用括号匹配检查系统  *****\n");
	printf("**************************************\n");
	printf("输入你要检测的代码(按ctrl + z 结束输入):\n");
	while ((code[count]=getchar())!=EOF){
		count++;
	}
	//检测括号匹配
	for (int i = 0; i < count; i++)
	{
		if (code[i] == '{' || code[i] == '(' || code[i] == '['){
			push(code[i]); 
		}
		if (code[i] == '}' || code[i] == ')' || code[i] == ']'){
			push(code[i]);
			cheak();
		}
	}

	if (stack_point == 0){
		printf("匹配成功\n");
	}else{
		printf("匹配失败\n");
	}
}
