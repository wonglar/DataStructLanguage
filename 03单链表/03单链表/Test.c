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

int main()
{
	//TestSList1();
	TestSList2();

	return 0;
}