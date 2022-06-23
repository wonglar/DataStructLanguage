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

// 尾部删除一
//void SListPopBack(SLTNode** pphead)
//{
//	SLTNode* tail = *pphead;
//	SLTNode* prev = NULL;
//
//	// 链表为空时
//	assert(*pphead != NULL);
//	// 只有一个节点时
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


// 尾部删除二
void SListPopBack(SLTNode** pphead)
{
	SLTNode* tail = *pphead;

	// 链表为空时
	assert(*pphead != NULL);

	// 只有一个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	// 两个或两个以上节点
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


// 头部删除
void SListPopFront(SLTNode** pphead)
{
	// 链表为空时
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

// 在pos位置之前去插入一个节点(单链表不适合在pos的前面插入)
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
		// 找到pos的前一个位置
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = newnode;
		newnode->next = pos;
	}

	
}