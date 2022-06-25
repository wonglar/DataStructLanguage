#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

void TestSList1()
{

	SLTNode* plist = NULL;
	// 尾部插入
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	
	SListPrint(plist);

	// 头部插入
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

}

void TestSList2()
{

	SLTNode* plist = NULL;

	// 头部插入
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

}


void TestSList3()
{

	SLTNode* plist = NULL;

	// 尾部插入
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	// 尾部删除
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);



	SListPrint(plist);
}

void TestSList4()
{

	SLTNode* plist = NULL;

	// 尾部插入
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	// 头部删除
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);


	SListPrint(plist);
}


void TestSList5()
{

	SLTNode* plist = NULL;

	// 尾部插入
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 2);
	int i = 1;
	while (pos)
	{
		printf("第%d个pos节点:%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	// SListFind还可以做修改
	// 修改3为30
	pos = SListFind(plist, 3);
	if (pos)
	{
		pos->data = 30;
	}

	SListPrint(plist);
}

void TestSList6()
{

	SLTNode* plist = NULL;

	// 尾部插入
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}

	SListPrint(plist);

	pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 10);
	}

	SListPrint(plist);
}

//int main()
//{
//	//TestSList1();
//	//TestSList2();
//
//	//TestSList3();
//
//	//TestSList4();
//
//	//TestSList5();
//
//	TestSList6();
//
//	return 0;
//}