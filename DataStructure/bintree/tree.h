
typedef char BTDataType;

typedef struct BinTreeNode{
    BTDataType data;
    struct BinTreeNode* left;
    struct BinTreeNode* right;
}BinTreeNode;


BinTreeNode* CreateBinTree(BTDataType *str, int size, BTDataType invalid);
//前序遍历
void PreOrder(BinTreeNode *pRoot);
//中序遍历
void InOrder(BinTreeNode *pRoot);
//后序遍历
void PosOrder(BinTreeNode *pRoot);

//前序非递归遍历
void PreOrderNor(BinTreeNode *pRoot);
//中序非递归遍历
void InOrderNor(BinTreeNode *pRoot);
//后序非递归遍历
void PosOrderNor(BinTreeNode *pRoot);

int BTreeHeight(BinTreeNode *pRoot);

void BTreeDestory(BinTreeNode **pRoot);

BinTreeNode* BTreeCopy(BinTreeNode *pRoot);

int GetBTreeSize(BinTreeNode *pRoot);

int GetLeafNodeCount(BinTreeNode *pRoot);

int GetKLevelNodeCount(BinTreeNode *pRoot, int k);

BinTreeNode* BTreeFind(BinTreeNode *pRoot, BTDataType data);

void test();