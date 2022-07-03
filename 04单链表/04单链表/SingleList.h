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

// ��ʼ������
Status ListInit(LinkList *L);

// �п� (ͷָ���ͷ�����Ȼ��)
Status ListEmpty(LinkList L);

// ��������
Status ListDestroy(LinkList* L);

// �������
Status ListClear(LinkList* L);


