#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"

// 测试尾插和尾删
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

	SqListPrint(&sl);



	SqListDestory(&sl);
}

// 测试头插和头删
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

	SqListPopFront(&sl);
	SqListPopFront(&sl);
	SqListPopFront(&sl);
	SqListPrint(&sl);


	SqListDestory(&sl);
}

// 测试SqListFind
void TestSqList3()
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

	printf("%d\n", SqListFind(&sl, 30));
	printf("%d\n", SqListFind(&sl, 5));
	printf("%d\n", SqListFind(&sl, 50));


	SqListDestory(&sl);
}


// 测试在指定位置插入
void TestSqList4()
{
	SqList sl;
	SqListInit(&sl);
	SqListPushBack(&sl, 1);
	SqListPushBack(&sl, 2);
	SqListPushBack(&sl, 3);
	SqListPushBack(&sl, 4);
	SqListPushBack(&sl, 5);
	SqListPrint(&sl);

	SqListInsert(&sl, 2, 20);
	SqListPrint(&sl);

	// 在4的位置插入40
	int index = SqListFind(&sl, 4);
	if (index != -1)
	{
		SqListInsert(&sl, index+1, 40);
	}
	SqListPrint(&sl);

	SqListInsert(&sl, 1, 10);
	SqListPrint(&sl);

	SqListInsert(&sl, 9, 90);
	SqListPrint(&sl);


	SqListDestory(&sl);
}


// 测试删除pos位置的数据
void TestSqList5()
{
	SqList sl;
	SqListInit(&sl);
	SqListPushBack(&sl, 1);
	SqListPushBack(&sl, 2);
	SqListPushBack(&sl, 3);
	SqListPushBack(&sl, 4);
	SqListPushBack(&sl, 5);
	SqListPushBack(&sl, 6);
	SqListPrint(&sl);

	// 顺序表的当前长度
	int len = GetLength(&sl);
	printf("len = %d\n", len);
	
	// 删除第一个位置的元素
	SqListErase(&sl, 1);
	SqListPrint(&sl);

	// 删除顺序表中的5
	int index = SqListFind(&sl, 5);
	if (index != -1)
	{
		SqListErase(&sl, index + 1);
	}
	SqListPrint(&sl);

	// 顺序表的当前长度
	len = GetLength(&sl);
	printf("len = %d\n", len);

	// 顺序表是否为空
	int ret = isEmpty(&sl);
	printf("顺序表是否为空：%d\n", ret);

	SqListDestory(&sl);
}


// 测试获取指定位置元素
void TestSqList6()
{
	SqList sl;
	SqListInit(&sl);
	SqListPushBack(&sl, 1);
	SqListPushBack(&sl, 2);
	SqListPushBack(&sl, 3);
	SqListPushBack(&sl, 4);
	SqListPushBack(&sl, 5);
	SqListPrint(&sl);

	ElemType e;
	int ret = GetElem(&sl, 4, &e);
	if (ret == 0)
	{
		printf("要获取元素的位置不合法！\n");
	}
	else
	{
		printf("%d\n", e);
	}

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

//int main()
//{
//
//	 //TestSqList1();
//
//	 //TestSqList2();
//
//	//TestSqList3();
//
//	 //TestSqList4();
//
//	// TestSqList5();
//
//	 TestSqList6();
//
//	return 0;
//}
