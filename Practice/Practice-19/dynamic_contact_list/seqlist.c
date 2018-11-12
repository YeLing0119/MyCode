#include <stdlib.h>
#include "seqlist.h"
#include <stdio.h>
#include <assert.h>


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
		pCon->_capacity *= 2;
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

void SeqListPushFront(pContact pCon , DataType data);

void SeqListPopFront(pContact pCon);

void SeqListInster(pContact pCon , int pos , DataType data);

void SeqListErase(pContact pCon , int pos);

void SeqListFind(pContact pCon, DataType data);

void SeqListRemove(pContact pCon , DataType data);

void SeqListRemoveAll(pContact pCon , DataType data);

int SeqListSize(pContact pCon);

int SeqListCapacity(pContact pCon);

DataType GetSeqListFirstElem(pContact pCon);

DataType GetSeqListLastElem(pContact pCon);

void SeqListClear(pContact pCon);

void SeqListDestory(pContact pCon);

void CheackCapacity(pContact pCon);

void BubbleSort(pContact Pcon);


