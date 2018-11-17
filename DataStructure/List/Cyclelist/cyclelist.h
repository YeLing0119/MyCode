#pragma once 

typedef int DataType;

typedef struct CycDataList{
    struct CycDataList *_prev;
    DataType data;
    struct CycDataList *_next;
}CycListNode;

typedef struct Dlist{
    struct CycDataList *head;
}DList;

void ListInit(DList* plist);
void ListDestory(DList* plist);
void ListPushBack(DList* plist, DataType x);
void ListPopBack(DList* plist);
void ListPushFront(DList* plist, DataType x);
void ListPopFront(DList* plist);
CycListNode* ListFind(DList* plist, DataType x);
// 在pos的前面进行插入
void ListInsert(DList* pos, DataType x);
// 删除pos位置的节点
void ListErase(DList* pos);
void ListRemove(DList* plist, DataType x);
void ListPrint(DList* plist);