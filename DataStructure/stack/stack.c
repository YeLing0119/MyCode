#include "stack.h"
#include <stdio.h>

void StackInit(Stack *pStack, int size){
    pStack->_pArray = (SDataType*)malloc(sizeof(SDataType)*size);

    pStack->_capitity = size;
    pStack->_top = 0;
}

void StackPush(Stack *pStack, SDataType data){
    if(pStack->_pArray == NULL){
        printf("UnInit Stack\n");
        return 0;
    }

    if(pStack->_capitity == pStack->_top){
        printf("Stack Full, realloc....\n");

        SDataType *pA = realloc(pStack->_pArray , sizeof(SDataType)*pStack->_capitity*2);
    }

    pStack->_pArray[pStack->_top] = data;
    pStack->_top++;
}

void StachPop(Stack *pStack){
    if(pStack->_top == 0){
        printf("Empty Stack\n");
        return;
    }
    pStack->_top--;
}

SDataType* StackTop(Stack* pStack){
    if(pStack->_top == 0){
        printf("Empty Stack");
        return NULL;
    }   

    return pStack->_pArray[pStack->_top - 1];
}

void StackEmpty(Stack* pStack){
    return pStack->_top == 0;
}

void StackDestory(Stack* pStack){
    free(pStack->_pArray);

    pStack->_capitity = 0;
    pStack->_top = 0;
}

void test();