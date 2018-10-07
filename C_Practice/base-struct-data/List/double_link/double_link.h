#ifndef __DOUBLE_LINK_H__
#define __DOUBLE_LINK_H__

typedef struct Double_link  Double_link_t;

struct Double_link{
	Double_link_t *prev;
	Double_link_t *next;
	void *data;
};

//初始化
void Double_link_init(Double_link_t **phead);

//插入
void Double_link_insert(Double_link_t *head, void *data);

//显示
void Double_link_show(Double_link_t *head, void (*pf)(void *d));

//删除
void Double_link_erase(Double_link_t *head, void *data);

//销毁
void Double_link_destroy(Double_link_t **phead);

#endif //__DOUBLE_LINK_H__

