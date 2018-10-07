#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "double_link.h"

//初始化
void Double_link_init(Double_link_t **phead)
{
	Double_link_t *p = malloc(sizeof(Double_link_t));
	memset(p, 0x00, sizeof(Double_link_t));	

	p->next = p;
	p->prev = p;
	
	*phead = p;
}

//插入
void Double_link_insert(Double_link_t *head, void *data)
{
	Double_link_t *p = malloc(sizeof(Double_link_t));	
	memset(p, 0x00, sizeof(Double_link_t));	
	
	p->data = data;
	
	p->prev = head->prev;
	p->next = head;
	head->prev->next = p;
	head->prev = p;
}

//显示
void Double_link_show(Double_link_t *head, void (*print)(void *d))
{
	Double_link_t *cur = head->next;
	while(cur != head)
	{
		print(cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//删除
void Double_link_erase(Double_link_t *head, void *data)
{

}

//销毁
void Double_link_destroy(Double_link_t **phead)
{

}

