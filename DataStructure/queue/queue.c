#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

QueueNode* CreatNode(QDataType data){
    QueueNode* pNew = (QueueNode*)malloc(sizeof(QueueNode));
    if(pNew == NULL){
        printf("Malloc failure\n");
        return NULL;
    }

    pNew->_pNext = NULL;
    pNew->data = data;

    return pNew;
}

void QueueInit(Queue *pQue){
    assert(pQue);

    pQue->_pFront = NULL;
    pQue->_pBack = NULL;

}
void QueuePush(Queue *pQue, QDataType data){
    assert(pQue);
    
    QueueNode *pNewNode = CreatNode(data);
    if(pNewNode == NULL){
        printf("Push Failure\n");
        return;
    }

    if(pQue->_pFront == NULL){
        pQue->_pFront = pQue->_pBack = pNewNode;
    }

    pQue->_pBack->_pNext = pNewNode;
    pQue->_pBack = pNewNode;
}

void QueuePop(Queue *pQue){
    assert(pQue);
    if(!QueueEmpty(pQue)){
        if(pQue->_pFront == pQue->_pBack){
            free(pQue->_pFront);
            pQue->_pFront = pQue->_pBack = NULL;
        }else{
            QueueNode *pDel = pQue->_pFront;
            pQue->_pFront = pDel->_pNext;
            free(pDel);
        }
    }
}\

QDataType QueueFront(Queue *pQue){
    assert(pQue);

    return pQue->_pFront->data;
}
QDataType QueueBack(Queue *pQue){
    assert(pQue);

    return pQue->_pBack->data;
}

int QueueSize(Queue *pQue){
    assert(pQue);
    int count = 0;
    QueueNode* pCur = pQue->_pFront;
    if(pCur == NULL)
        return count;
    while(pCur!=NULL){
        count++;
        pCur = pCur->_pNext;
    }
    return count;
}

int QueueEmpty(Queue *pQue){
    return NULL == pQue->_pFront;
}

void QueueDestory(Queue *pQue){
    assert(pQue);

    QueueNode* pDel = pQue->_pFront;

    while(pDel){
        pQue->_pFront = pDel->_pNext;
        free(pDel);
        pDel = pQue->_pFront;
    }

    pQue->_pFront = pQue->_pBack = NULL;
}

void PrintfQueue(Queue *pQue){
    QueueNode* pCur = pQue->_pFront;

    while(pCur){
        printf("%d  ", pCur->data);
        pCur = pCur->_pNext;
    }

    printf("\n");
}

void test(){
    Queue Que;
    QueueInit(&Que);

    QueuePush(&Que, 1);
    QueuePush(&Que, 2);
    QueuePush(&Que, 3);
    QueuePush(&Que, 4);
    QueuePush(&Que, 5);

    printf("\n%d  \n", QueueFront(&Que));
    printf("%d  \n", QueueBack(&Que));

    PrintfQueue(&Que);
    QueuePop(&Que);
    QueuePop(&Que);
    QueuePop(&Que);
    QueuePop(&Que);
    printf("%d  \n", QueueFront(&Que));
    printf("%d  \n", QueueBack(&Que));
    QueuePop(&Que);
    PrintfQueue(&Que);

    QueueDestory(&Que);

    printf("%p %p \n", Que._pFront, Que._pBack);
}