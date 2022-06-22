#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

// ����һ���ڵ�
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

// ��ӡ������
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

// β������
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

// ͷ������
void SListPushFront(SLTNode** pphead, ElementType e)
{
	SLTNode* newnode = CreateListNode(e);

	newnode->next = *pphead;
	*pphead = newnode;
}