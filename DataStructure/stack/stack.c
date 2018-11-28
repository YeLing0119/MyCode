#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void StackInit(Stack *pStack, int size){
    assert(pStack);

    pStack->_pArray = (SDataType*)malloc(sizeof(SDataType)*size);

    pStack->_capitity = size;
    pStack->_top = 0;
}

void StackPush(Stack *pStack, SDataType data){
    assert(pStack);

    if(pStack->_pArray == NULL){
        printf("UnInit Stack\n");
        return;
    }

    if(pStack->_capitity == pStack->_top){
        printf("Stack Full, realloc....\n");
        SDataType *pA = (SDataType*)realloc(pStack->_pArray , sizeof(SDataType)*pStack->_capitity*2);
        pStack->_capitity *= 2;
    }

    pStack->_pArray[pStack->_top] = data;
    pStack->_top++;
}

void StackPop(Stack *pStack){
    assert(pStack);
    
    if(pStack->_top == 0){
        printf("Empty Stack\n");
        return;
    }
    pStack->_top--;
}

SDataType StackTop(Stack* pStack){
    assert(pStack);
    
    if(pStack->_top == 0){
        printf("Empty Stack\n");
        return NULL;
    }   

    return pStack->_pArray[pStack->_top - 1];
}

int StackEmpty(Stack* pStack){
    assert(pStack);
    return pStack->_top == 0;
}

void StackDestory(Stack* pStack){
    assert(pStack);

    free(pStack->_pArray);

    pStack->_capitity = 0;
    pStack->_top = 0;
}

void test(){
    Stack Sta;

    StackInit(&Sta, 5);

    StackPush(&Sta, 1);
    StackPush(&Sta, 2);
    StackPush(&Sta, 3);
    StackPush(&Sta, 4);
    StackPush(&Sta, 5);

    printf("%d  ", StackTop(&Sta));
    StackPop(&Sta);

    printf("%d  ", StackTop(&Sta));
    StackPop(&Sta);
    
    printf("%d  \n", StackTop(&Sta));
    StackPop(&Sta);

    printf("Empty : %d  \n" , StackEmpty(&Sta));
    
    printf("%d  ", StackTop(&Sta));
    StackPop(&Sta);
    
    printf("%d  \n", StackTop(&Sta));
    StackPop(&Sta);

    printf("NULL : %d  \n" , StackTop(&Sta));
    StackPop(&Sta);

    printf("Empty : %d  \n" , StackEmpty(&Sta));

    StackPush(&Sta , 1);
    StackPush(&Sta , 2);
    StackPush(&Sta , 3);
    StackPush(&Sta , 4);
    StackPush(&Sta , 5);
    StackPush(&Sta , 6);

    printf("%d  \n" , StackTop(&Sta));
    printf("Capitity : %d  \n" , Sta._capitity);
}