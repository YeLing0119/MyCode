#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

int Greater(HDataType left, HDataType right){
    return left > right;
}
int Less(HDataType left, HDataType right){
    return left < right;
}

void CheckCapitity(Heap *pH){
    assert(pH);
    if(pH->_capitity == pH->_size){
        HDataType* pNew = (HDataType*)realloc(pH->_pArray, sizeof(HDataType)*pH->_capitity*2);
        if(pNew == NULL){
            printf("Realloc Failure : ");
            perror("realloc");
            return;
        }
        pH->_pArray = pNew;
        pH->_capitity *= 2;
    }
}

void PrintHeap(Heap *pH){
    assert(pH);
    for(int i = 0; i < pH->_size; i++){
        printf("%d  ", pH->_pArray[i]);
    }
    printf("\n");
}

void HeapSwap(HDataType* pam1, HDataType* pam2){
    HDataType temp = *pam1;
    *pam1 = *pam2;
    *pam2 = temp;
}

//向下调整
void AdjustDown(Heap *pH, int root){
    int parent = root;

    int child = parent * 2 + 1;

    while(child < pH->_size){
        if(child + 1 < pH->_size && pH->pCom(pH->_pArray[child], pH->_pArray[child + 1])){
            child += 1;
        }

     if(pH->pCom(pH->_pArray[parent], pH->_pArray[child])){
            HeapSwap(&pH->_pArray[parent], &pH->_pArray[child]);
            parent = child;
            child = parent * 2 + 1;
        }else{
            return;
        }
    }
}

void AdjustUp(Heap *pH, int pos){
    assert(pH);

    if(pos > pH->_size){
        return;
    }

    int child = pos;
    int parent = (child - 2) >> 1;

    while(child >= 0){
        if(pH->pCom(pH->_pArray[parent], pH->_pArray[child])){
            HeapSwap(&pH->_pArray[parent], &pH->_pArray[child]);
            child = parent;
            parent = (child - 2) >> 1;
        }else{
            return;
        }
    }
}

void HeapInit(Heap *pH, HDataType *Arr, int size, PF pCom){
    assert(pH);
    assert(Arr);

    pH->_pArray = (HDataType*)malloc(sizeof(HDataType)*size);
    if(pH->_pArray == NULL){
        printf("Init Failure \n");
        return ;
    }

    for(int i = 0 ; i < size ; ++i){
        pH->_pArray[i] = Arr[i];
    }

    pH->_capitity = size;
    pH->_size = size;
    pH->pCom = pCom;

    //Adjust
    int root = (size - 2) >> 1;
    for(; root >= 0; --root){
        AdjustDown(pH, root);
    }
}

void HeapInsert(Heap *pH, HDataType data){
    assert(pH);
    CheckCapitity(pH);

    pH->_pArray[pH->_size++] = data;

    AdjustUp(pH, pH->_size - 1);

    //HeapSwap(&pH->_pArray[0], &pH->_pArray[pH->_size - 1]);
    //int root = (pH->_size - 2) / 2;
    //for(; root >= 0; --root){
    //    AdjustDown(pH, root, pH->_size);
    //}
}

void HeapErase(Heap *pH){
    assert(pH);

    if(HeapEmpty(pH)){
        return;
    }

    HeapSwap(&pH->_pArray[0], &pH->_pArray[pH->_size - 1]);
    pH->_size--;

    AdjustDown(pH, 0);
}

HDataType HeapTop(Heap *pH){
    assert(pH);
    return pH->_pArray[0];
}

int HeapSize(Heap *pH){
    assert(pH);
    return pH->_size;
}

int HeapEmpty(Heap *pH){
    assert(pH);
    return 0 == pH->_size;
}

void HeapDestory(Heap *pH){
    assert(pH);
    free(pH->_pArray);

    pH->_capitity = 0;
    pH->_size = 0;
}

void test(){
    Heap pH;
    HDataType arr[] = {9,8,7,6,5,4,3,2,1,0};
    //HeapInit(&pH, arr, sizeof(arr)/sizeof(arr[0]), Greater);  //小堆
    HeapInit(&pH, arr, sizeof(arr)/sizeof(arr[0]), Less);       //大堆
    PrintHeap(&pH);

    printf("Size:%d\n", HeapSize(&pH));
    printf("Top:%d\n", HeapTop(&pH));
    printf("Empty:%d\n", HeapEmpty(&pH));

    HeapInsert(&pH, 0);
    PrintHeap(&pH);

    printf("Size:%d\n", HeapSize(&pH));
    printf("Top:%d\n", HeapTop(&pH));
    printf("Empty:%d\n", HeapEmpty(&pH));

    HeapErase(&pH);
    PrintHeap(&pH);

    HeapDestory(&pH);
    PrintHeap(&pH);
    printf("Size:%d\n", HeapSize(&pH));
    printf("Top:%d\n", HeapTop(&pH));
    printf("Empty:%d\n", HeapEmpty(&pH));
}