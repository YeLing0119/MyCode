#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *elem1 , void *elem2 , int size){
	char *_elem1 = (char *)elem1;
	char *_elem2 = (char *)elem2;
	int i = 0;
	for(i = 0 ; i < size ; i++){
		int tmp = *_elem1;
		*_elem1 = *_elem2;
		*_elem2 = tmp;
		_elem1++ , _elem2++;
	}
}

void MaoSort(void *buff , int num , int size , int (*compare)(const void * , const void *)){
	int i = 0;
	int j = 0;
	for(i = 0 ; i < num - 1 ; i++){
		for(j = 0 ; j < num - 1 - i ; j++){
			//printf("%d %d : ", i , j);
			//printf("%d %d  ---> " , *(int *)(((char *)buff + j * size)) , *(int *)(((char *)buff + (j + 1) * size)));
			if(compare((char *)buff + j * size , (char *)buff + (j + 1) * size) > 0){
				swap((char *)buff + j * size , (char *)buff + (j + 1) * size , size);
				//printf("%d %d" , *(int *)(((char *)buff + j * size)) , *(int *)(((char *)buff + (j + 1) * size)));
			}
			//printf("\n");
		}
	}
}


int ComInt(const void *elem1 , const void *elem2){
	return *((int *)elem1) - *((int *)elem2);
}

int ComString(const void *elem1 , const void *elem2){
	int ret = 0;
	while(!( ret = *(char*)elem1++ - *(char*)elem2++ ) && *(char *)elem1);
	return ret;
}

int ComPString(const void* elem1 , const void* elem2){
	int ret = 0;
	char *_elem1 = (char *)elem1;
	char *_elem2 = (char *)elem2;

	//printf("%s  %s \n " , _elem1 , _elem2);

	while(!(ret = (*_elem1) ++ - (*_elem2)++) && (*_elem1));
	
	
	return 0;
}

int main(){
	int arr[] = {5513, 8565, 6132, 3131, 4523, 4521, 6453, 9864, 4555, 6453};
	char str[][10] = {"abcd" , "ABcd" , "AbCd" , "aBcd" , "abCd"};
	char *pstr[10] = {"abcd" , "ABcd" , "AbCd" , "aBcd" , "abCd"};
	//swap(&arr[0],&arr[1] , 4);
	int i = 0;

	//整形数组
	for(i = 0 ; i < 10 ; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
	
	MaoSort(arr , 10 , 4 , ComInt);
	
	for(i = 0 ; i < 10 ; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
	
	//字符串数组排序
	for(i = 0 ; i < 5 ; i++){
		printf("%s  ", str[i]);
	}
	printf("\n");
	
	MaoSort(str , 5 , 10 , ComString);
	
	for(i = 0 ; i < 5 ; i++){
		printf("%s  ", str[i]);
	}
	printf("\n");

	//指针数组排序
	for(i = 0 ; i < 5 ; i++){
		printf("%s  ", *(pstr + i));
	}
	printf("\n");

	MaoSort(pstr , 5 , 4 , ComPString);
	
	for(i = 0 ; i < 5 ; i++){
		printf("%s  ", *(pstr + i));
	}
	printf("\n");
	
	exit(0);
}
