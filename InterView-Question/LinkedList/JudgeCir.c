#include <stdio.h>

typedef  struct LinkNode{
    int val ;
    struct LinkNode *next;
}LinkNode;

LinkNode* JudgeCycle(LinkNode *Head){
    LinkNode* pFast = Head;
    LinkNode* pSlow = Head;
    //Judge Cycle
    while(pFast != pSlow){
        pFast = pFast->next->next;
        pSlow = pSlow->next;
        if(pFast == pSlow){
            break;
        }
    }
    //if No Cycle
    //if(pFast != pSlow){       //错误的
    //    return NULL;
    //}
    if(NULL == pFast || NULL == pFast->next){
        return NULL;
    }
    //if with Cycle     return enter cycle addr 
    LinkNode* pH = pFast;
    LinkNode* pM = Head;
    while(pH != pM){
        pM = pM->next;
        pH = pH->next;
    }
}