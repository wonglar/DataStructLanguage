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

// 求链表表长
int ListLength(LinkList L);

// 取第pos个元素值
Status ListGetElem(LinkList L, int pos, ElementType* e);

// 取第pos个元素值
ListNode* ListGeetElem2(LinkList L, int pos);

// 按值查找,找到后返回该节点
ListNode* ListSearchByVal(LinkList L, ElementType e);

// 按值查找，找到后返回是第几个
int ListSearchByVal_pos(LinkList L, ElementType e);

// 指定位置插入，在第pos个节点位置插入一个新节点
Status ListInsert(LinkList* L, int pos, ElementType e);

// 创建一个新的节点
ListNode* ListCreateNewnode(ElementType e);

// 打印链表
void ListPrint(LinkList L);

// 删除第pos个节点
Status ListDeleteByPos(LinkList* L, int pos, ElementType* e);

// 头插建立单链表
void CreatList_H(LinkList* L, int n);

// 尾插法建立单链表
void CreatList_T(LinkList* L, int n);
