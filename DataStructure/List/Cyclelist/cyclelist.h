#pragma once

typedef int DataType;

typedef struct CListNode{
    struct CListNode* _pPre;
    DataType _Data;
    struct CListNode* _pNext;
}CListNode;

typedef struct HList{
    CListNode* _Head;
}CHList;

void ListInit(CHList* CList);
void ListDestory(CHList* CList);
void ListPushBack(CHList* CList, DataType data);
void ListPopBack(CHList* CList);
void ListPushFront(CHList* CList, DataType data);
void ListPopFront(CHList* CList);
CListNode* ListFind(CHList* CList, DataType data);

// 在pos的前面进行插入
void ListInsert(CHList* CList, CListNode* pos, DataType data);
// 删除pos位置的节点
void ListErase(CHList* CList, CListNode* pos);

void ListRemove(CHList* CList, DataType data);
void ListPrint(CHList* CList);

void test();