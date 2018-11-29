#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef int QDataType;

typedef struct QueueNode{
    struct QueueNode* _pNext;
    QDataType data;
}QueueNode;

typedef struct Queue{
    QueueNode* _pFront;
    QueueNode* _pBack;
}Queue;

void QueueInit(Queue *pQue);
void QueuePush(Queue *pQue, QDataType data);
void QueuePop(Queue *pQue);
QDataType QueueFront(Queue *pQue);
QDataType QueueBack(Queue *pQue);

int QueueSize(Queue *pQue);
int QueueEmpty(Queue *pQue);
void QueueDestory(Queue *pQue);

void test();

#endif