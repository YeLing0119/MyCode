#include "tree.h"
#include <stdio.h>

void PreOrder(BinTreeNode *pRoot){
    if(pRoot != NULL){
        printf("%c  ", pRoot->data);
        PreOrder(pRoot->left);
        PreOrder(pRoot->right);
    }
}

void InOrder(BinTreeNode *pRoot){
    if(pRoot != NULL){
        InOrder(pRoot->left);
        printf("%c  ", pRoot->data);
        InOrder(pRoot->right);
    }
}

void PosOrder(BinTreeNode *pRoot){
    if(pRoot != NULL){
        PosOrder(pRoot->left);
        PosOrder(pRoot->right);
        printf("%c  ", pRoot->data);
    }
}