#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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


// ͷ������
void SListPushFront(SLTNode** pphead, ElementType e);

// β��ɾ��
void SListPopBack(SLTNode** pphead);


// ͷ��ɾ��
void SListPopFront(SLTNode** pphead);


SLTNode* SListFind(SLTNode* phead, ElementType e);

// ��posλ��֮ǰȥ����һ���ڵ�
void SListInsert(SLTNode** pphead, SLTNode* pos, ElementType e);

// ��posλ��֮��ȥ����һ���ڵ�
void SListInsertAfter(SLTNode* pos, ElementType e);

void SListErase(SLTNode** pphead, SLTNode* pos);

void SListEraseAfter(SLTNode* pos);

void SListDestroy(SLTNode** pphead);

