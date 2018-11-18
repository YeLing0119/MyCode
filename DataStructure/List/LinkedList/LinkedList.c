#include "LinkedList.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

LinkNode* CreatNode(DataType data){
	LinkNode* pNewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (pNewNode == NULL){
		perror("malloc");
		printf("Error : malloc failure\n");
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void LinkListInit(LinkNode** pFir){
	//assert(pFir);
	*pFir = NULL;
}

void PrintLinkList(LinkNode* pFir){
	while (pFir){
		printf("%d -> ", pFir->data);
		pFir = pFir->_pNext;
	}
	printf("NULL\n");
}

void LinkListPushBack(LinkNode** pFir, DataType data){
	assert(pFir);
	LinkNode *pNewNode = CreatNode(data);
	//if (pNewNode == NULL){
	//	return;
	//}

	if (*pFir == NULL){
		//1 . ���������
		printf("Kong Insert Back\n");
		*pFir = pNewNode;

	}else{
		//2 . ������1��Ԫ�ز���
		LinkNode* lp = *pFir;
		printf("Fei Kong Insert Back\n");
		while (lp->_pNext != NULL){
			lp = lp->_pNext;
		}
		lp->_pNext = pNewNode;
	}
}

void LinkListPopBack(LinkNode** pFir){
	assert(pFir);
	
	if (*pFir == NULL){	//������
		printf("Empty List\n");
		return;
	}else if((*pFir)->_pNext == NULL){					//ֻ��һ��Ԫ�ص�����
		free((*pFir));
		*pFir = NULL;
	}else{
		LinkNode* lp = *pFir;
		while (lp->_pNext->_pNext != NULL){
			lp = lp->_pNext;
		}
		free(lp->_pNext);
		lp->_pNext = NULL;
	}
}


// 4 . Insert Element In Front
void LinkListPushFront(LinkNode** pFir, DataType data){
	assert(pFir);

	//if (*pFir == NULL){		//������
	//	LinkNode* pNewNode = CreatNode(data);
	//	if (pNewNode == NULL){
	//		printf("Creat Failure\n");
	//		return ;
	//	}
	//	*pFir = pNewNode;
	//}else{		//�ǿ�����
		LinkNode* pNewNode = CreatNode(data);
		//if (pNewNode == NULL){
		//	printf("Creat Failure\n");
		//	return ;
		//}		
		pNewNode->_pNext = *pFir;
		*pFir = pNewNode;
	//}
}

// 5 . Erase Element In Front
void LinkListPopFront(LinkNode** pFir){
	assert(pFir);
	
	if (*pFir == NULL){
		printf("Empty \n");
		return;
	}
	else{
		LinkNode* pl = *pFir;
		*pFir = (*pFir)->_pNext;
		free(pl);
	}
}

LinkNode* LinkListFind(LinkNode* pFir, DataType data){
	while (pFir){
		if (pFir->data == data){
			return pFir;
		}
		pFir = pFir->_pNext;
	}
	return NULL;
}

void LinkListInsert(LinkNode* pos, DataType data){
	if (pos == NULL) return;
	LinkNode* pNewNode = CreatNode(data);
	if (pNewNode == NULL){
		printf("error :��Creat Failure\n");
		return;
	}
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

void LinkListErase(LinkNode** pFir,LinkNode* pos){
	assert(pFir);

	if (pos == NULL || (*pFir) == NULL){
		return;
	}
	if (pos == *pFir){
		*pFir = (*pFir)->_pNext;
	}
	else{
		LinkNode* posPre = *pFir;
		while (posPre->_pNext != pos){
			posPre = posPre->_pNext;
		}
		posPre->_pNext = pos->_pNext;
	}
	free(pos);
}

void LinkListDestory(LinkNode** pFir){
	LinkNode* pDel = *pFir;
	while (*pFir){
		pDel = *pFir;
		*pFir = (*pFir)->_pNext;
		free(pDel);
	}
}


int LinkListSize(LinkNode* pFir){
	int count = 0;
	if (pFir == NULL){
		return count;
	}
	while (pFir){
		++count;
		pFir = pFir->_pNext;
	}
	return count;
}

void LinkListEmpty(LinkNode* pFir){
	
}

DataType GetLinkListFront(LinkNode* pFir){
	assert(pFir);
	return pFir->data;
}

DataType GetLinkListBack(LinkNode* pFir){
	assert(pFir);
	LinkNode* pCur = pFir;
	while (pCur->_pNext != NULL){
		pCur = pCur->_pNext;
	}
	return pCur->data;
}

void LinkListRemove(LinkNode** pFir, DataType data){
	assert(pFir);

	LinkNode* pCur = pFir;
	LinkNode* pPre = NULL;

	while (pCur){
		if (pCur->data = data){
			if (pCur == pFir){
				*pFir = pCur;
			}else{
				pPre->_pNext = pCur->_pNext;
			}
			free(pCur);
			return;
		}else{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
	}
}

// 15 . Remove All Specified Data
void LinkListRemoveAll(LinkNode** pFir, DataType data){
	assert(pFir);

	LinkNode* pCur = pFir;
	LinkNode* pPre = NULL;

	while (pCur){
		if (pCur->data = data){
			if (pCur == pFir){
				*pFir = pCur;
				free(pCur);
				pCur = *pFir;
			}
			else{
				pPre->_pNext = pCur->_pNext;
				free(pCur);
				pCur = pPre->_pNext;
			}
		}
		else{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
	}
}


//Test
void Test(){
	LinkNode* pFirst;	//����ָ���һ���ڵ��ָ��
	LinkListInit(&pFirst);
	printf("Linked List Size = %d \n", LinkListSize(pFirst));
	LinkListPushBack(&pFirst, 1);
	LinkListPushBack(&pFirst, 2);
	LinkListPushBack(&pFirst, 3);
	LinkListPushBack(&pFirst, 4);
	PrintLinkList(pFirst);
	printf("Linked List Size = %d \n", LinkListSize(pFirst));
	//printf("%p -> %d\n", LinkListFind(pFirst, 3), LinkListFind(pFirst, 3)->data);

	LinkListInsert(LinkListFind(pFirst, 3), 7);
	PrintLinkList(pFirst);

	LinkListInsert(LinkListFind(pFirst, 1), 7);
	PrintLinkList(pFirst);

	LinkListInsert(LinkListFind(pFirst, 4), 7);
	PrintLinkList(pFirst);

	printf("Linked List Size = %d \n", LinkListSize(pFirst));

	LinkListErase(&pFirst, LinkListFind(pFirst, 7));
	LinkListErase(&pFirst, LinkListFind(pFirst, 7));
	LinkListErase(&pFirst, LinkListFind(pFirst, 1));
	PrintLinkList(pFirst);
	printf("Linked List Size = %d \n", LinkListSize(pFirst));

	//LinkListDestory(&pFirst);
	//PrintLinkList(pFirst);
	system("pause");
}
