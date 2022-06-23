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

// β��ɾ��һ
//void SListPopBack(SLTNode** pphead)
//{
//	SLTNode* tail = *pphead;
//	SLTNode* prev = NULL;
//
//	// ����Ϊ��ʱ
//	assert(*pphead != NULL);
//	// ֻ��һ���ڵ�ʱ
//	if ((*pphead)->next == NULL)
//	{
//		free(*pphead);
//		*pphead = NULL;
//	}
//	else
//	{
//		while (tail->next != NULL)
//		{
//			prev = tail;
//			tail = tail->next;
//		}
//
//		free(tail);
//		tail = NULL;
//		prev->next = NULL;
//
//	}
//
//}


// β��ɾ����
void SListPopBack(SLTNode** pphead)
{
	SLTNode* tail = *pphead;

	// ����Ϊ��ʱ
	assert(*pphead != NULL);

	// ֻ��һ���ڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	// �������������Ͻڵ�
	else
	{
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}

}


// ͷ��ɾ��
void SListPopFront(SLTNode** pphead)
{
	// ����Ϊ��ʱ
	assert(*pphead != NULL);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}


SLTNode* SListFind(SLTNode* phead, ElementType e)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == e)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}

	return NULL;
}

// ��posλ��֮ǰȥ����һ���ڵ�(�������ʺ���pos��ǰ�����)
void SListInsert(SLTNode** pphead, SLTNode* pos, ElementType e)
{
	SLTNode* newnode = CreateListNode(e);

	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		// �ҵ�pos��ǰһ��λ��
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = newnode;
		newnode->next = pos;
	}

	
}