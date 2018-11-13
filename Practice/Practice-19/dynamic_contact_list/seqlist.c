#include <stdlib.h>
#include "seqlist.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

void SeqListInit(pContact pCon, int capacity){
	//Judge paramater legality  判断参数的合法性
	assert(pCon);
	if(capacity <= 0){
		printf("Capacity lower than 0 \n");
		return ;
	}
	//After judge , malloc space in heap	判断之后，在堆上开辟空间  
	pDataType pd = NULL;
	pd = (pDataType)malloc(capacity*sizeof(DataType));
	if(pd == NULL){
		perror("malloc");
		return ; 
	}
	
	//If success deliver pd to pCon->AddrList 如果开辟成功，则把pd 传给 pCon->AddrList
	pCon->AddrList;
	pCon->_capacity = capacity;
	pCon->_size = 0;
	
	printf("Init Success \n");
}

void SeqListPushBack(pContact pCon , DataType data){
	
	assert(pCon);
	//cheak list is full ?  检查线性表是否满了
	if(pCon->_size == pCon->_capacity){
		pDataType pd = NULL;
		printf("Insufficient storage , Appending...\n");	//空间不足，追加中...
		pd = (pDataType)realloc(pCon->AddrList , 2*pCon->_capacity*sizeof(DataType));
		if(pd == NULL){
			printf("Append failure!\n");
			perror("realloc");
			return ;	
		}
		pCon->AddrList = pd;
		pCon->_capacity = 2 * pCon->_capacity;
	}
	//Add in Back 	在后面添加
	pCon->AddrList[pCon->_size] = data;
	pCon->_size++;

	printf("Add Success \n");
}

void SeqListPopBack(pContact pCon){
	if(pCon->_size == 0){
		printf("List Is Empty Can't Delete\n");
		return ;
	}
	
	pCon->_size--;
	printf("Delete Last One Success !\n");
}

void SeqListPushFront(pContact pCon , DataType data){
	assert(pCon);
	
	if(pCon->_capacity == pCon->_size){
		printf("Insufficient storage , Appending...\n");	//空间不足，追加中...
		pDataType pdt = (pDataType)realloc(pCon->AddrList, 2 * pCon->_capacity * sizeof(DataType));
		if(pdt == NULL){
			printf("Append failure!\n");
			perror("realloc");
			return ;
		}

		pCon->AddrList = pdt;
		pCon->_capacity = pCon->_capacity * 2;
	}

	pCon->_size++;
	int count = pCon->_size;
	while(count > 0){
		pCon->AddrList[count] = pCon->AddrList[count - 1];
		count--;
	}

	pCon->AddrList[0] = data;
	
}

void SeqListPopFront(pContact pCon){
	assert(pCon);
	pCon->_size--;
	int count = 0;
	for( ; count < pCon->_size ; count++){
		pCon->AddrList[count] = pCon->AddrList[count + 1];
	}
}

void SeqListInster(pContact pCon , int pos , DataType data){
	assert(pCon);
	if(pCon->_capacity == pCon->_size){
		printf("Insufficient storage , Appending...\n");	//空间不足，追加中...
		pDataType pdt = (pDataType)realloc(pCon->AddrList, 2 * pCon->_capacity * sizeof(DataType));
		if(pdt == NULL){
			printf("Append failure!\n");
			perror("realloc");
			return ;
		}
	}
	
	pCon->_size++;
	int count = pCon->_size;
	
	while(count > pos){
		pCon->AddrList[count] = pCon->AddrList[count - 1];
		count--;
	}

	pCon->AddrList[pos] = data;
}

void SeqListErase(pContact pCon , int pos){
	assert(pCon);
	assert(pos > 0);
	
	int count = pos;
	pCon->_size--;
	for(; count < pCon->_size; count++){
		pCon->AddrList[count] = pCon->AddrList[count + 1];
	}
}

int SeqListFind(pContact pCon, char* name){
	int count = 0;
	
	assert(pCon);
	assert(name);
	
	for(; count < pCon->_size ; count++){
		if(strcmp(pCon->AddrList[count].name, name)){
			return count;
		}
	}
	return 0;
}

void SeqListRemove(pContact pCon , char* name){
	assert(pCon);
	assert(name);
	
	int count = 0;
	for(; count < pCon->_size ; count++){
		if(strcmp(pCon->AddrList[count].name, name) == 0){
			SeqListErase(pCon , count);
			pCon->_size--;
			return ;
		}
	}
}

void SeqListRemoveAll(pContact pCon , char* name){
	assert(pCon);
	assert(name);
	
	int count = 0;
	for(; count < pCon->_size ; count++){
		if(strcmp(pCon->AddrList[count].name, name) == 0){
			SeqListErase(pCon , count);
			pCon->_size--;
		}
	}
}

int SeqListSize(pContact pCon){
	assert(pCon);
	return pCon->_size;
}

int SeqListCapacity(pContact pCon){
	assert(pCon);
	return pCon->_capacity;
}

DataType GetSeqListFirstElem(pContact pCon){
	assert(pCon);
	return pCon->AddrList[0];
}

DataType GetSeqListLastElem(pContact pCon){
	assert(pCon);
	DataType dt = {"none" , "none" , 0 , "none" , "none"};
	if(pCon->_size == 0){
		printf("List is Empty! Can't get last Elem!\n");
		return dt;
	}
	return pCon->AddrList[pCon->_size - 1];
}

void SeqListClear(pContact pCon){
	assert(pCon);
	pCon->_size = 0;	
}

void SeqListDestory(pContact pCon){
	assert(pCon);
	
	free(pCon->AddrList);
	pCon->_size = 0;
	pCon->_capacity = 0;
}

void CheackCapacity(pContact pCon){

}

void BubbleSort(pContact pCon){
	int count_row = 0;
	int count_col = 0;
	
	for(count_row = 0; count_row < pCon->_size ; count_row++){
		for(count_col = 0 ; count_col < pCon->_size - count_row - 2 ; count_col){
			if(strcmp(pCon->AddrList[count_col].name , pCon->AddrList[count_col+1].name)){
				DataType tmp = pCon->AddrList[count_col];
				pCon->AddrList[count_col + 1] = pCon->AddrList[count_col];
				pCon->AddrList[count_col] = tmp;
			}		
		}	
	}		
}


