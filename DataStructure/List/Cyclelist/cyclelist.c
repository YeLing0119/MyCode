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
        printf("CycList NULL \n");
        return ;
    }

    //顺序打印
    CListNode* pCur = CList->_Head->_pNext;
    while(pCur != CList->_Head){
        printf("%d --> " , pCur->_Data);
        pCur = pCur->_pNext;
    }
    printf("Head\n");

    //反向打印
    //CListNode* pCurPre = CList->_Head->_pPre;
    //while(pCurPre != CList->_Head){
    //    printf("%d --> ", pCurPre->_Data);
    //    pCurPre = pCurPre->_pPre;
    //}
    //printf("Head\n");
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

void ListPopBack(CHList* CList){
    assert(CList);
    
    //如果是空链表
    if(CList->_Head->_pNext == CList->_Head){
        printf("CycList is Empty! \n");
        return;
    }
    //至少有一个节点
    CListNode *pDel = CList->_Head->_pPre;

    CList->_Head->_pPre = pDel->_pPre;
    pDel->_pPre->_pNext = CList->_Head;
    free(pDel);
}   

void ListPushFront(CHList* CList, DataType data){
    assert(CList);
    
    CListNode *pNewNode = CreatNode(data);

    pNewNode->_pNext = CList->_Head->_pNext;
    pNewNode->_pPre = CList->_Head->_pPre;

    CList->_Head->_pNext = pNewNode;
    pNewNode->_pNext->_pPre = pNewNode;
}
void ListPopFront(CHList* CList){
    assert(CList);
    //没有节点
    if(CList->_Head->_pNext == CList->_Head){
        printf("CycList Empty\n");
        return ;
    }

    //至少有一个节点
    CListNode *pDel = CList->_Head->_pNext;

    CList->_Head->_pNext = pDel->_pNext;
    pDel->_pNext->_pPre = CList->_Head;

    free(pDel);
}

CListNode* ListFind(CHList* CList, DataType data){
    assert(CList);
    if(CList->_Head->_pNext == CList->_Head){
        return NULL;
    }

    CListNode *pCur = CList->_Head->_pNext;
    while(pCur != CList->_Head){
        if(pCur->_Data == data){
            return pCur;
        }
        pCur = pCur->_pNext;
    }

    return NULL;
}


void ListInsert(CHList* CList, CListNode* pos, DataType data){
    assert(pos);

    CListNode *pNewNode = CreatNode(data);

    pNewNode->_pNext = pos->_pNext;
    pNewNode->_pPre = pos;

    pos->_pNext = pNewNode;
    pNewNode->_pNext->_pPre = pNewNode;
}
void ListErase(CHList* CList, CListNode* pos){
    assert(pos);

    if(pos == CList->_Head){       //头结点不能删除
        printf("Can't Erase Head Point\n");
        return;
    }
    
    //至少有一个节点
    pos->_pPre->_pNext = pos->_pNext;
    pos->_pNext->_pPre = pos->_pPre;

    free(pos);
}

void ListRemove(CHList* CList, DataType data){
    assert(CList);

    if(CList->_Head->_pNext == CList->_Head){
        printf("CycList Empty\n");
        return;
    }

    CListNode *pCur = CList->_Head->_pNext;
    CListNode *pTemp = NULL;
    while(pCur != CList->_Head){
        if(pCur->_Data == data){
            ListErase(CList, pCur);
            //pTemp = pCur->_pNext;
            //pCur->_pPre->_pNext = pCur->_pNext;
            //pCur->_pNext->_pPre = pCur->_pPre;
            //free(pCur);
            //pCur = pTemp;
            //pCur = CList->_Head->_pNext;
            ListPrint(CList);
        }else{
            pCur = pCur->_pNext;
        }
    }
}

void test1(){       //测试尾插和尾删
    CHList CList;
    ListInit(&CList);
    ListPushBack(&CList , 1);
    ListPushBack(&CList , 2);
    ListPushBack(&CList , 3);
    ListPushBack(&CList , 4);
    ListPushBack(&CList , 5);
    ListPrint(&CList);

    ListPopBack(&CList);
    ListPrint(&CList);

    ListPopBack(&CList);
    ListPrint(&CList);
}

void test2(){   //测试头插和头删 以及寻找
    CHList CList;
    ListInit(&CList);
    ListPushFront(&CList,5);
    ListPushFront(&CList,4);
    ListPushFront(&CList,3);
    ListPushFront(&CList,2);
    ListPushFront(&CList,1);
    ListPrint(&CList);

    ListPopFront(&CList);
    ListPrint(&CList);    
    //ListPopFront(&CList);
    //ListPrint(&CList);    
    //ListPopFront(&CList);
    //ListPrint(&CList);    
    //ListPopFront(&CList);
    //ListPrint(&CList);    
    //ListPopFront(&CList);
    //ListPrint(&CList);

    CListNode *pRet = ListFind(&CList,2);
    if(pRet == NULL){
        printf("Not Find \n");
    }else{
        printf("Find it  : Addr is %p\n" , pRet);
    }

    pRet = ListFind(&CList,10);
    if(pRet == NULL){
        printf("Not Find \n");
    }else{
        printf("Find it \n Addr is %p" , pRet);
    }
}


void test3(){
    CHList CList;
    ListInit(&CList);
    ListPushFront(&CList,5);
    ListPushFront(&CList,4);
    ListPushFront(&CList,3);
    ListPushFront(&CList,2);
    ListPushFront(&CList,1);
    ListPrint(&CList);

    //ListErase(&CList, CList._Head);
    //ListPrint(&CList);

    ListErase(&CList, ListFind(&CList, 2));
    ListPrint(&CList);

    ListInsert(&CList, CList._Head, 10);
    ListPrint(&CList);
}

void test4(){
    CHList CList;
    ListInit(&CList);
    ListPushFront(&CList,2);
    ListPushFront(&CList,4);
    ListPushFront(&CList,2);
    ListPushFront(&CList,2);
    ListPushFront(&CList,2);
    ListPushFront(&CList,3);
    ListPushFront(&CList,2);
    ListPushFront(&CList,2);
    ListPushFront(&CList,1);
    ListPushFront(&CList,2);
    ListPrint(&CList);

    ListRemove(&CList, 2);
    ListPrint(&CList);
}
void test(){
    //test1();
    //test2();
    //test3();
    test4();
}