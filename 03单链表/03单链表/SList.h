#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct SListNode
{
	ElementType data;
	struct SListNode* next;
}SLTNode;

// 打印单链表
void SListPrint(SLTNode* phead);


// 尾部插入
void SListPushBack(SLTNode** phead, ElementType e);
