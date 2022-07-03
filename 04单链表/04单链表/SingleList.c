#define _CRT_SECURE_NO_WARNINGS 1
/*
	��ͷ���ĵ�����
*/

#include "SingleList.h"


// ��ʼ������
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


// �п� (ͷָ���ͷ�����Ȼ��)
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


// ��������
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

// �������
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

