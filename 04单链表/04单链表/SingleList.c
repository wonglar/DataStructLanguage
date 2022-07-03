#define _CRT_SECURE_NO_WARNINGS 1
/*
	带头结点的单链表
*/

#include "SingleList.h"


// 初始化链表
Status ListInit(LinkList* L)
{
	*L = (ListNode*)malloc(sizeof(struct ListNode));
	if (*L == NULL)
	{
		exit(OVERFLOW);
	}

	(*L)->next = NULL;

	return OK;
}


// 判空 (头指针和头结点仍然在)
Status ListEmpty(LinkList L)
{
	if (L->next)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}


// 销毁链表
Status ListDestroy(LinkList* L)
{
	ListNode* p;
	while (*L)
	{
		p = *L;
		*L = (*L)->next;
		free(p);
		p = NULL;
	}

	return OK;
}

// 清空链表
Status ListClear(LinkList* L)
{
	assert(*L);

	ListNode* p, * q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = NULL;
		p = q;
	}

	(*L)->next = NULL;

	return OK;
}

