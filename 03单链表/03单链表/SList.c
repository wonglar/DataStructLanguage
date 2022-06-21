#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"


// 打印单链表
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}

}

// 尾部插入
void SListPushBack(SLTNode** phead, ElementType e)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = e;
	newnode->next = NULL;

	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		SLTNode* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}


}