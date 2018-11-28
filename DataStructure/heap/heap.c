#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

void CheckCapitity(Heap *pH){
    assert(pH);
    if(){

    }
}

void HeapSwap(HDataType* pam1, HDataType* pam2){
    int temp = *pam1;
    *pam1 = *pam2;
    *pam2 = temp;
}

//向下调整
void AdjustDown(Heap *pH, int root , int size){
    int parent = root;

    int child = root * 2 + 1;

    while(child < size){
        if(child + 1 < size && pH->_pArray[child] < pH->_pArray[child + 1]){
            child += 1;
        }

        if(pH->_pArray[parent] < pH->_pArray[child]){
            HeapSwap(&pH->_pArray[parent], &pH->_pArray[child]);
            parent = child;
            child = parent*2+1;
        }
    }
}

void HeapInit(Heap *pH, HDataType *Arr, int size){
    assert(pH);
    assert(Arr);

    pH->_pArray = (HDataType*)malloc(sizeof(HDataType)*size);
    if(pH->_pArray == NULL){
        printf("Init Failure \n");
        return ;
    }

    for(int i = 0 ; i < size ; i++)
        pH->_pArray[i] = Arr[i];

    pH->_capitity = size;
    pH->_size = size;

    //Adjust
    int root = (size-2)/2;
    for(; root >= 0; --root){
        AdjustDown(pH, root, size);
    }
}

void HeapInstert(Heap *pH, HDataType data){
    assert(pH);
    CheckCapitity(*pH);

    pH->_pArray[pH->_size++] = data;

    HeapSwap(&pH->_pArray[0], &pH->_pArray[pH->_size - 1]);

    AdjustDown(pH, 0 ,pH->_size);
}

void HeapErase(Heap *pH){
    assert(pH);
}

int HeapEmpty(Heap *pH){
    return 0 == pH->_size;
}

void HeapDestory(Heap *pH){
    free(pH->_pArray);

    pH->_capitity = 0;
    pH->_size = 0;
}

void PrintHeap(Heap *pH){
    for(int i = 0; i < pH->_size; i++){
        printf("%d  ", pH->_pArray[i]);
    }
    printf("\n");
}

void test(){
    Heap pH;
    HDataType arr[] = {1,5,2,8,4,3};
    HeapInit(&pH, arr, sizeof(arr)/sizeof(arr[0]));
    PrintHeap(&pH);

    HeapInstert(&pH, 0);
    PrintHeap(&pH);
}