#ifndef __SEQLIST_H__
#define __SEQLIST_H__

typedef struct AddressList{
	char name[32];
	char sex[6];
	char age;
	char tele[15];
	char addr[128];
}DataType , *pDataType;

typedef struct Contact{
	pDataType AddrList;
	int _capacity;
	int _size;
}Contact, *pContact;

//初始化线性表
void SeqListInit(pContact pCon, int capacity);

//在顺序表尾部插入元素data
void SeqListPushBack(pContact pCon , DataType data);

//删除顺序表中的最后一个元素
void SeqListPopBack(pContact pCon);

//在顺序表头部插入元素
void SeqListPushFront(pContact pCon , DataType data);

//删除顺序表头部的元素
void SeqListPopFront(pContact pCon);

//在顺序表的pos位置插入元素data
void SeqListInster(pContact pCon , int pos , DataType data);

//删除顺序表pos位置的元素
void SeqListErase(pContact pCon , int pos);

//在顺序表中寻找name值为指定值的第一次出现的位置
int SeqListFind(pContact pCon, char* name);

//删除顺序表中name值为指定值的元素
void SeqListRemove(pContact pCon , char* name);

//删除顺序表中所有name值为指定值的元素
void SeqListRemoveAll(pContact pCon , char* name);

//获取顺序表中有效元素的个数
int SeqListSize(pContact pCon);

//获取顺序表的容量
int SeqListCapacity(pContact pCon);

//获取顺序表中第一个元素
DataType GetSeqListFirstElem(pContact pCon);

//获取顺序表中最后一个元素的个数
DataType GetSeqListLastElem(pContact pCon);

//清空顺序表中有效元素的个数
void SeqListClear(pContact pCon);

//销毁顺序表
void SeqListDestory(pContact pCon);

//检测容量
void CheackCapacity(pContact pCon);

//用冒泡排序对顺序表的所有元素排序
void BubbleSort(pContact pCon);

#endif
