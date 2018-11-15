#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


typedef int DataType;


typedef struct LinkNode{
	DataType data;
	struct LinkNode* _pNext;
}LinkNode;

// 1 . Init Linked List
void InitLinkList(LinkNode** pFir);

// 2 . Insert Element In Last
void LinkListPushBack(LinkNode** pFir, DataType data);

// 3 . Erase Element In Last
void LinkListPopBack(LinkNode** pFir);

// 4 . Insert Element In Front
void LinkListPushFront(LinkNode** pFir, DataType data);

// 5 . Erase Element In Front
void LinkListPopFront(LinkNode** pFir);

// 6 . Find Element In LinkList
LinkNode* LinkListFind(LinkNode* pFir, DataType data);

// 7 . Insert Element In AnyWhere
void LinkListInsert(LinkNode* pos, DataType data);

// 8 . Erase Element In AnyWhere
void LinkListErase(LinkNode** pFir, LinkNode* pos);

// 9 . Destory All Linked List
void LinkListDestory(LinkNode** pFir);

// 10 . Get Size Of Linked List
int LinkListSize(LinkNode* pFir);

// 11 . Empty Linked List
void LinkListEmpty(LinkNode* pFir);

// 12 . Get Front Element In Linked List
DataType GetLinkListFront(LinkNode* pFir);

// 13 . Get Back Element In Linked List
DataType GetLinkListBack(LinkNode* pFir);

// 14 . Remove Specified Data
void LinkListRemove(LinkNode** pFir , DataType data);

// 15 . Remove All Specified Data
void LinkListRemoveAll(LinkNode** pFir, DataType data);

// 16 . 
void LinkListBubbleSort(LinkNode* pFir);

//Test 
void Test();


#endif		//__LINKED_LIST_H__
