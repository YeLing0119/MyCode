#include "cyclelist.h"
#include <malloc.h>
#include <assert.h>


void ListInit(DList* plist){
    assert(plist);
    plist->head = CreatNode();
    plist->head->_next = plist->head;
    plist->head->_prev = plist->head;
}