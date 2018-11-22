#ifndef __STACK_H__
#define __STACK_H__

typedef int SDataType;

typedef struct Stack{
    SDataType *_pStack;
    int _capitity;
    int _top;
}Stack;

void StackInit(Stack *pStack);

void StackPush(Stack *pStack);

void StachPop(Stack *pStack);

void test();

#endif