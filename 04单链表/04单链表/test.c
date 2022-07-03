#define _CRT_SECURE_NO_WARNINGS 1
#include "SingleList.h"

// 测试初始化、判空、销毁、清空
void TestList01()
{
	LinkList list;
	// 初始化单链表
	ListInit(&list);

	int ret = ListEmpty(list);
	if (ret)
	{
		printf("链表为空！\n");
	}
	else
	{
		printf("链表非空！\n");
	}

	ListDestroy(&list);

	ListClear(&list);

}

// 测试指定位置插入，在第pos个节点位置插入一个新节点
void TestList02()
{
	LinkList list;
	// 初始化单链表
	ListInit(&list);

	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	ListInsert(&list, 3, 3);
	ListInsert(&list, 4, 4);
	ListPrint(list);

}

// 测试按值查找和取第pos个元素值
void TestList03()
{
	LinkList list;
	// 初始化单链表
	ListInit(&list);

	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	ListInsert(&list, 3, 3);
	ListInsert(&list, 4, 4);
	ListPrint(list);

	ListNode* p = ListSearchByVal(list, 3);
	if (p != NULL)
	{
		printf("%d\n", p->data);
	}
	else
	{
		printf("未找到该值！\n");
	}

	int pos = ListSearchByVal_pos(list, 1);
	if (pos)
	{
		printf("%d\n", pos);
	}
	else
	{
		printf("未找到该值的位置！\n");
	}

	ElementType e;
	int ret = ListGetElem(list, 3, &e);
	if (ret)
	{
		printf("e = %d\n", e);
	}
}


void TestList04()
{

	LinkList list;
	// 初始化单链表
	ListInit(&list);

	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	ListInsert(&list, 3, 3);
	ListInsert(&list, 4, 4);
	ListPrint(list);

	ElementType e;
	ListDeleteByPos(&list, 3, &e);
	ListPrint(list);
	printf("删除的元素是：%d\n", e);
}


void TestList05()
{
	LinkList list;
	CreatList_H(&list, 5);
	ListPrint(list);

}


void TestList06()
{
	LinkList list;
	CreatList_T(&list, 5);
	ListPrint(list);

}


int main()
{
	TestList06();

	return 0;
}