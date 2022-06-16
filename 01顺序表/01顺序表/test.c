#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"

void TestSqList1()
{
	SqList sl;
	SqListInit(&sl);
	SqListPushBack(&sl, 1);
	SqListPushBack(&sl, 2);
	SqListPushBack(&sl, 3);
	SqListPushBack(&sl, 4);
	SqListPushBack(&sl, 5);
	SqListPrint(&sl);

	SqListPopBack(&sl);
	SqListPopBack(&sl);
	SqListPopBack(&sl);
	SqListPopBack(&sl);
	SqListPopBack(&sl);
	SqListPopBack(&sl);
	SqListPrint(&sl);



	SqListDestory(&sl);
}


void TestSqList2()
{
	SqList sl;
	SqListInit(&sl);
	SqListPushBack(&sl, 1);
	SqListPushBack(&sl, 2);
	SqListPushBack(&sl, 3);
	SqListPushBack(&sl, 4);
	SqListPushBack(&sl, 5);
	SqListPrint(&sl);

	SqListPushFront(&sl, 10);
	SqListPushFront(&sl, 20);
	SqListPushFront(&sl, 30);
	SqListPushFront(&sl, 40);
	SqListPrint(&sl);


	SqListDestory(&sl);
}

//int main()
//{
//
//	// TestSqList1();
//
//	TestSqList2();
//
//
//	return 0;
//}
