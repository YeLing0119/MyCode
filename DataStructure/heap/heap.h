#ifndef __HEAP_H__
#define __HEAP_H__

typedef int HDataType;

typedef int (*PF)(HDataType left, HDataType right);

typedef struct Heap{
    HDataType* _pArray;
    int _capitity;
    int _size;
    PF pCom;
}Heap;

int Greater(HDataType left, HDataType right);
int Less(HDataType left, HDataType right);

void HeapInit(Heap *pH, HDataType *Arr, int size, PF pCom);

void HeapInsert(Heap *pH, HDataType data);

void HeapErase(Heap *pH);

HDataType HeapTop(Heap *pH);

int HeapSize(Heap *pH);

HDataType* HeapSort(int *array, int size);

int HeapEmpty(Heap *pH);

void HeapDestory(Heap *pH);

void test();


#endif // __HEAP_H__