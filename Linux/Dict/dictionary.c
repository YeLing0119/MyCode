#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char yinwen[50];
	char zhongwen[50];
}Dict_t;

int count = 0 ; //表示数据读到哪一个,读取完成后表示该单词表的最后一个单词是第几个
Dict_t words[8000];


//加载dictionary.txt文件
void LoadFile(void){
	int sum = 1108;
	FILE *fp = fopen ("dictionary_all.txt","r");
	if( fp == NULL ){
		perror("fopen");
		exit(0);
	}

	// 读取数据
	while ( !feof(fp) ){
		fscanf(fp, "%s\t%s", 
					words[count].yinwen,
					words[count].zhongwen);
		printf("%s | %s \n", words[count].yinwen, 
							 words[count].zhongwen);
		count++;
		if(count == sum){
			fclose(fp);
			break;
		}
	}

	fclose(fp);
}

//利用二分法查找指定单词
int BinSearch(const char* buffer){
	int left = 0;
	int right = count - 1;
	
	while(left <= right){
	
		int mid = left + (right - left) / 2; //求中间的数
	
		printf("left = %d , mid = %d ,right = %d\n", left, mid, right);
		printf("英文 : %s \n", words[mid].yinwen);	
		if(strcmp(words[mid].yinwen,buffer) == 0){
			printf("找到了:%d\n", mid);
			return mid;		//找到，返回的单词下标
		}else if(strcmp(words[mid].yinwen, buffer) > 0){
			right = mid - 1;
		}else{
			left  = mid + 1 ;
		}
	}
	//没有找到
	return -1;
}

int main(){
	//加载文件
	LoadFile();
	
	//请求用户输入
	char buff[100];
	int suffix_words = 0;		//记录返回的单词下标
	while(1){
		printf("请输入单词\n");
		memset(buff,0x00,sizeof(buff));
		scanf("%s", buff);
		if( (suffix_words = BinSearch(buff)) == -1 ){
			printf("没有找到单词:%s\n", buff);
		}else{
			printf("%s | %s \n", words[suffix_words].yinwen, 
								 words[suffix_words].zhongwen);
		}
	}
}
