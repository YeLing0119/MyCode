#include <stdlib.h>
#include <queue>
#include "tree.h"
using namespace std;

int Level(const BTree* Root)
{
    queue<BTree> que;
    
    if ( Root == NULL)
        return 0;

    que.push(*Root);

}

int Judge(const BTree* Root)
{
    queue<BTree> que;
    if(Root == NULL)
        return 0;
    que.push(*Root);
}

int K_Point(BTree* Root, int K)
{
    if(Root == NULL)
        return 0;
}