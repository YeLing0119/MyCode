#ifndef __HEAP_H__
#define __HEAP_H__

typedef int HDataType;

typedef struct Heap{
    HDataType* _pArray;
    int _capitity;
    int _size;
}Heap;

void HeapInit(Heap *pH, HDataType *Arr, int size);

void HeapInstert(Heap *pH, HDataType data);

void HeapErase(Heap *pH);

int HeapEmpty(Heap *pH);

void HeapDestory(Heap *pH);

void test();


#endif // __HEAP_H__