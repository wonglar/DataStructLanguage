#define _CRT_SECURE_NO_WARNINGS 1
/*
	��ͷ���ĵ�����
*/

#include "SingleList.h"

// ����һ���µĽڵ�
ListNode* ListCreateNewnode(ElementType e)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(struct ListNode));
	if (newnode == NULL)
	{
		exit(OVERFLOW);
	}

	newnode->data = e;
	newnode->next = NULL;
	return newnode;
}

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


// �������
int ListLength(LinkList L)
{
	assert(L);
	ListNode* p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}


// ȡ��pos��Ԫ��ֵ����ʽһ��
Status ListGetElem(LinkList L, int pos, ElementType* e)
{
	ListNode* p = L->next;
	int i = 1;
	while (p && i < pos)
	{
		p = p->next;
		i++;
	}

	if (i > pos || p == NULL)
	{
		return ERROR;
	}

	*e = p->data;

	return OK;
}


//// ȡ��pos��Ԫ��ֵ(��ʽ��)
//ListNode* ListGeetElem(LinkList L, int pos)
//{
//	assert(pos >= 1 && pos <= ListLength(L));
//
//	ListNode* p = L->next;
//	int i = 1;
//	while (i != pos)
//	{
//		p = p->next;
//		i++;
//	}
//
//	return p;
//}

// ��ֵ����
ListNode* ListSearchByVal(LinkList L, ElementType e)
{
	ListNode* p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
	}

	return p;
}


// ��ֵ���ң��ҵ��󷵻��ǵڼ���
int ListSearchByVal_pos(LinkList L, ElementType e)
{
	ListNode* p = L->next;
	int i = 1;
	while (p && p->data != e)
	{
		p = p->next;
		i++;
	}

	if (p)
		return i;
	else
		return 0;
}


// ָ��λ�ò��룬�ڵ�pos���ڵ�λ�ò���һ���½ڵ�(��ʽһ)
Status ListInsert(LinkList* L, int pos, ElementType e)
{
	assert(L);
	assert(pos>=1 && pos <= ListLength(*L)+1);

	ListNode* newnode = ListCreateNewnode(e);

	ListNode* prev = *L;
	int i = 0;
	for (i = 0; i < pos - 1; i++)
	{
		prev = prev->next;
	}

	newnode->next = prev->next;
	prev->next = newnode;

	return OK;
}

// ָ��λ�ò��룬�ڵ�pos���ڵ�λ�ò���һ���½ڵ㣨��ʽ����
//Status ListInsert(LinkList* L, int pos, ElementType e)
//{
//	ListNode* p = *L;
//	int i = 0;
//	while (p && i < pos - 1)
//	{
//		p = p->next;
//		i++;
//	}
//
//	if (!p || i > pos - 1)
//	{
//		return ERROR;
//	}
//
//	// ����һ���µĽڵ�
//	ListNode* newnode = ListCreateNewnode(e);
//	
//	newnode->next = p->next;
//	p->next = newnode;
//	return OK;
//}

// ��ӡ����
void ListPrint(LinkList L)
{
	ListNode* cur = L->next;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// ɾ����pos���ڵ�
Status ListDeleteByPos(LinkList* L, int pos, ElementType* e)
{
	ListNode* p = *L, *q;
	int i = 0;
	while (p->next && i < pos - 1)
	{
		p = p->next;
		i++;
	}

	// ɾ��λ�ò�����
	if (!(p->next) || i > pos - 1)
		return ERROR;

	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	q = NULL;

	return OK;
}


// ͷ�彨��������
void CreatList_H(LinkList* L, int n)
{
	*L = (ListNode*)malloc(sizeof(struct ListNode));
	(*L)->next = NULL;
	int i = 0;
	for (i = n; i > 0; i--)
	{
		ElementType e;
		scanf("%d", &e);
		ListNode* newnode = ListCreateNewnode(e);

		newnode->next = (*L)->next;
		(*L)->next = newnode;
	}
}

// β�巨����������
void CreatList_T(LinkList* L, int n)
{
	*L = (ListNode*)malloc(sizeof(struct ListNode));
	(*L)->next = NULL;

	ListNode* tail = (*L);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		ElementType e;
		scanf("%d", &e);
		ListNode* newnode = ListCreateNewnode(e);
		
		tail->next = newnode;
		tail = newnode;
	}
}
