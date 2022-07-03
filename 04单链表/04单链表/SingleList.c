#define _CRT_SECURE_NO_WARNINGS 1
/*
	带头结点的单链表
*/

#include "SingleList.h"

// 创建一个新的节点
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


// 求链表表长
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


// 取第pos个元素值（方式一）
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


//// 取第pos个元素值(方式二)
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

// 按值查找
ListNode* ListSearchByVal(LinkList L, ElementType e)
{
	ListNode* p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
	}

	return p;
}


// 按值查找，找到后返回是第几个
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


// 指定位置插入，在第pos个节点位置插入一个新节点(方式一)
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

// 指定位置插入，在第pos个节点位置插入一个新节点（方式二）
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
//	// 创建一个新的节点
//	ListNode* newnode = ListCreateNewnode(e);
//	
//	newnode->next = p->next;
//	p->next = newnode;
//	return OK;
//}

// 打印链表
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

// 删除第pos个节点
Status ListDeleteByPos(LinkList* L, int pos, ElementType* e)
{
	ListNode* p = *L, *q;
	int i = 0;
	while (p->next && i < pos - 1)
	{
		p = p->next;
		i++;
	}

	// 删除位置不合理
	if (!(p->next) || i > pos - 1)
		return ERROR;

	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	q = NULL;

	return OK;
}


// 头插建立单链表
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

// 尾插法建立单链表
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
