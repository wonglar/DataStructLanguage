#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

// 创建一个节点
SLTNode* CreateListNode(ElementType e)
{

	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));

	if (newnode == NULL)
	{
		exit(-1);
	}

	newnode->data = e;
	newnode->next = NULL;

	return newnode;
}

// 打印单链表
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}

	printf("NULL\n");

}

// 尾部插入
void SListPushBack(SLTNode** phead, ElementType e)
{
	SLTNode* newnode = CreateListNode(e);

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

// 头部插入
void SListPushFront(SLTNode** pphead, ElementType e)
{
	SLTNode* newnode = CreateListNode(e);

	newnode->next = *pphead;
	*pphead = newnode;
}