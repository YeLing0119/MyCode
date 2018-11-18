#include "cyclelist.h"
#include <malloc.h>
#include <assert.h>

CListNode* CreatNode(DataType data){
    CListNode* pNew = (CListNode*)malloc(sizeof(CListNode));
    if(pNew == NULL){
        printf("Error : Creat New Node Failure\nReason : ");
        perror("malloc");
        return NULL;
    }
    pNew->_Data = data;
    pNew->_pPre = NULL;
    pNew->_pNext = NULL;
    return pNew;
}

void ListPrint(CHList* CList){
    assert(CList);

    if(CList->_Head->_pNext == CList->_Head){
        printf("NULL\n");
    }

    //顺序打印
    CListNode* pCur = CList->_Head->_pNext;
    while(pCur != CList->_Head){
        printf("%d --> " , pCur->_Data);
        pCur = pCur->_pNext;
    }
    printf("Head\n");

    //反向打印
    CListNode* pCurPre = CList->_Head->_pPre;

    while(pCurPre != CList->_Head){
        printf("%d --> ", pCurPre->_Data);
        pCurPre = pCurPre->_pPre;
    }
    printf("Head\n");
}

void ListInit(CHList* CList){
    assert(CList);

    CList->_Head = CreatNode(0);

    CList->_Head->_pPre = CList->_Head;
    CList->_Head->_pNext = CList->_Head;
}

void ListPushBack(CHList* CList , DataType data){
    CListNode* pNewNode = CreatNode(data);

    pNewNode->_pNext = CList->_Head;
    pNewNode->_pPre = CList->_Head->_pPre;
    
    pNewNode->_pPre->_pNext = pNewNode;
    CList->_Head->_pPre = pNewNode;
}

void ListPopBack(){
    
}

void test1(){
    CHList CList;
    ListInit(&CList);
    ListPushBack(&CList , 1);
    ListPushBack(&CList , 2);
    ListPushBack(&CList , 3);
    ListPushBack(&CList , 4);
    ListPushBack(&CList , 5);
    ListPrint(&CList);
}

void test(){
    test1();
}