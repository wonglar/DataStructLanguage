#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef int ElementType;


typedef struct ListNode
{
	ElementType data;
	struct ListNode* next;

}ListNode, *LinkList;

// 初始化链表
Status ListInit(LinkList *L);

// 判空 (头指针和头结点仍然在)
Status ListEmpty(LinkList L);

// 销毁链表
Status ListDestroy(LinkList* L);

// 清空链表
Status ListClear(LinkList* L);


