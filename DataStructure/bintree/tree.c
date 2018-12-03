#include "tree.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

BinTreeNode* CreateNode(BTDataType data){
    BinTreeNode *pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pNewNode == NULL){
        printf("malloc failure\n");
        return NULL;
    }

    pNewNode->data = data;
    pNewNode->left = NULL;
    pNewNode->right = NULL;

    return pNewNode;
}

void _CreateBinTree(BTDataType *str, BinTreeNode **pRoot, int *index, int size, BTDataType invalid){
    //二叉树　＝　根　＋　左子树　＋　右子树
    
    //创建根节点
    assert(pRoot);

    if(*index < size && str[*index] != invalid){
        *pRoot = CreateNode(str[*index]);

        //创建根节点的左子树
        (*index)++;
        _CreateBinTree(str, &(*pRoot)->left, index, size, invalid);

        //创建根节点的右子树
        (*index)++;
        _CreateBinTree(str, &(*pRoot)->right, index, size, invalid);
    }
}

BinTreeNode* CreateBinTree(BTDataType *str, int size, BTDataType invalid){
    BinTreeNode *pRoot = NULL;
    int index = 0;
    _CreateBinTree(str, &pRoot, &index, size, invalid);

    return pRoot;
}

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

int BTreeHeight(BinTreeNode* pRoot){
    if(pRoot == NULL){
        return 0;
    }

    int leftheight = BTreeHeight(pRoot->left);
    int rightheight = BTreeHeight(pRoot->right);

    return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
}

void BTreeDestory(BinTreeNode **pRoot){
    assert(pRoot);

    if(*pRoot){
        BTreeDestory(&(*pRoot)->left);
        BTreeDestory(&(*pRoot)->right);
        free((*pRoot));
        *pRoot = NULL;
    }
}

BinTreeNode* BTreeCopy(BinTreeNode *pRoot){
    BinTreeNode* pNewNode = NULL;
    if(pRoot){
        pNewNode = CreateNode(pRoot->data);
        if(pRoot->left == NULL)
            pNewNode->left = BTreeCopy(pRoot->left);
        if(pRoot->right == NULL)
            pNewNode->right = BTreeCopy(pRoot->right);
    }
    return pNewNode;
}

int GetBTreeSize(BinTreeNode *pRoot){
    if(pRoot == NULL){
        return 0;
    }

    return GetBTreeSize(pRoot->left) + GetBTreeSize(pRoot->right) + 1;    
}

int GetLeafNodeCount(BinTreeNode *pRoot){
    if(pRoot == NULL){
        return 0;
    }

    if(pRoot->left == NULL && pRoot->right ==NULL){
        return 1;
    }

    return GetLeafNodeCount(pRoot->left) + GetLeafNodeCount(pRoot->right);
}

int GetKLevelNodeCount(BinTreeNode *pRoot, int k){
    if(pRoot == NULL || k <= 0){
        return 0;
    }

    if(k == 1){
        return 1;
    }

    return GetKLevelNodeCount(pRoot->left, k - 1) + GetKLevelNodeCount(pRoot->right, k - 1);
}

BinTreeNode* BTreeFind(BinTreeNode *pRoot, BTDataType data){
    if(pRoot == NULL){
        return NULL;
    }

    if(pRoot->data == data){
        return pRoot;
    }

    BinTreeNode *pRet = NULL;

    if(pRet = BTreeFind(pRoot->left, data)){
        return pRet;
    }

    return BTreeFind(pRoot->right, data);
}


void test(){
    BTDataType *pStr = "ABD###CE##F";
    BinTreeNode *pRoot = NULL;
    pRoot = CreateBinTree(pStr, strlen(pStr), '#');

    printf("二叉树中节点的个数：%d\n", GetBTreeSize(pRoot));
    printf("二叉树中叶子节点的个数：%d\n", GetLeafNodeCount(pRoot));
    printf("二叉树第%d层节点的个数：%d\n", 3, GetKLevelNodeCount(pRoot, 3));

    BinTreeNode *pTemp = BTreeFind(pRoot, 'A');
    printf("Find : %p : %c \n", pTemp, pTemp->data);

    printf("PreOrder : ");
    PreOrder(pRoot);
    printf("\n");

    printf("InOrder : ");
    InOrder(pRoot);
    printf("\n");

    printf("PosOrder : ");
    PosOrder(pRoot);
    printf("\n");

    printf("Tree Height : %d \n", BTreeHeight(pRoot));

    BinTreeNode *pNewTree = NULL;
    pNewTree = BTreeCopy(pRoot);

    printf("PreOrder : ");
    PreOrder(pNewTree);
    printf("\n");

    BTreeDestory(&pNewTree);
    
    printf("PreOrder : ");
    PreOrder(pNewTree);
    printf("\n");
}