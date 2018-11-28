#ifndef __STACK_H__
#define __STACK_H__

typedef int SDataType;

typedef struct Stack{
    SDataType *_pArray;
    int _capitity;
    int _top;
}Stack;
// 初始化
void StackInit(Stack *pStack, int size);
// 压栈
void StackPush(Stack *pStack, SDataType data);
// 出栈
void StachPop(Stack *pStack);
// 获取栈顶元素
SDataType* StackTop(Stack* pStack);
// 栈判空
void StackEmpty(Stack* pStack);
// 栈销毁
void StackDestory(Stack* pStack);

void test();

#endif