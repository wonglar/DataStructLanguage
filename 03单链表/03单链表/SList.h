#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct SListNode
{
	ElementType data;
	struct SListNode* next;
}SLTNode;

// ��ӡ������
void SListPrint(SLTNode* phead);


// β������
void SListPushBack(SLTNode** phead, ElementType e);
