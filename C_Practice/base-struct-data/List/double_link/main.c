#include <stdio.h>
#include <stdlib.h>
#include "double_link.h"

typedef struct stu{
	int id;
	char name[1024];
}stu_t;

void myprintf(void *data)
{
	stu_t *p = data;
	printf("id = %d , name = %s\n", p->id, p->name);
}

int main()
{
	Double_link_t *head = NULL;
	
	Double_link_init(&head);
	
	stu_t s1 = {1,"zahngsan"};
	stu_t s2 = {2,"lisi"};
	stu_t s3 = {3,"wamhmazi"};
	Double_link_insert(head, (void *)&s1);
	Double_link_insert(head, (void *)&s2);
	Double_link_insert(head, (void *)&s3);
	
	Double_link_show(head,myprintf);
	
	return 0;
}


