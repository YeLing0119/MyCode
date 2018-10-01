#include<stdio.h>

#define LIST_INIT_SIZE 100 
#define LISTINCREMENT 10

typedef int ElemType;
typedef int status;

typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;

status InitList(Sqlist &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)exit(OVERFLOW);
	L.length=0;
	L.listsize=LIST_INIT_SZIE;
	return 0;
}

int main()
{
	printf("Welcome to line-list system!");
	printf("The system is initializing!\nplease wait!");
	Sqlist L;
	status flag = InitList(&L);
	if(flag==0)printf("Initializing success!");
	return 0;
}
