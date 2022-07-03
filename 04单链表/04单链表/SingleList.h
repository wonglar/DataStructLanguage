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

// �������
int ListLength(LinkList L);

// ȡ��pos��Ԫ��ֵ
Status ListGetElem(LinkList L, int pos, ElementType* e);

// ȡ��pos��Ԫ��ֵ
ListNode* ListGeetElem2(LinkList L, int pos);

// ��ֵ����,�ҵ��󷵻ظýڵ�
ListNode* ListSearchByVal(LinkList L, ElementType e);

// ��ֵ���ң��ҵ��󷵻��ǵڼ���
int ListSearchByVal_pos(LinkList L, ElementType e);

// ָ��λ�ò��룬�ڵ�pos���ڵ�λ�ò���һ���½ڵ�
Status ListInsert(LinkList* L, int pos, ElementType e);

// ����һ���µĽڵ�
ListNode* ListCreateNewnode(ElementType e);

// ��ӡ����
void ListPrint(LinkList L);

// ɾ����pos���ڵ�
Status ListDeleteByPos(LinkList* L, int pos, ElementType* e);

// ͷ�彨��������
void CreatList_H(LinkList* L, int n);

// β�巨����������
void CreatList_T(LinkList* L, int n);
