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

// 打印单链表
void SListPrint(SLTNode* phead);


// 尾部插入
void SListPushBack(SLTNode** phead, ElementType e);


// 头部插入
void SListPushFront(SLTNode** pphead, ElementType e);

// 尾部删除
void SListPopBack(SLTNode** pphead);


// 头部删除
void SListPopFront(SLTNode** pphead);


SLTNode* SListFind(SLTNode* phead, ElementType e);

// 在pos位置之前去插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, ElementType e);

// 在pos位置之后去插入一个节点
void SListInsertAfter(SLTNode* pos, ElementType e);

void SListErase(SLTNode** pphead, SLTNode* pos);

void SListEraseAfter(SLTNode* pos);

void SListDestroy(SLTNode** pphead);

