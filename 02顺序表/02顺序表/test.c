#define _CRT_SECURE_NO_WARNINGS 1

#include "SqList.h"

void TestSqList1()
{
	SqList sl;
	// 初始化顺序表
	SqListInit(&sl);

	Element e1 = { 1000, "C语言程序设计", 79.9 };
	SqListPushBack(&sl, &e1);

	Element e2 = { 1001, "数据结构", 65.9 };
	SqListPushBack(&sl, &e2);

	Element e3 = { 1002, "java语言设计", 52.5 };
	SqListPushBack(&sl, &e3);

	Element e4 = { 1003, "计算机网络", 75.9 };
	SqListPushBack(&sl, &e4);

	Element e5 = { 1004, "操作系统", 85.0 };
	SqListPushBack(&sl, &e5);

	// 打印顺序表中的元素
	SqListPrint(&sl);
	

	// 根据位置获取相应位置数据元素的内容
	Element e;
	int ret = SqListGetElem(&sl, 3, &e);
	if (ret)
	{
		printf("%d %s %lf\n", e.bid, e.bname, e.bprice);
	}
	else
	{
		printf("要获取的元素位置不合理!\n");
	}




	// 销毁顺序表
	SqListDestory(&sl);
}

// 测试顺序表插入（在指定位置插入）
void TestSqList2()
{
	SqList sl;
	// 初始化顺序表
	SqListInit(&sl);

	Element e1 = { 1000, "C语言程序设计", 79.9 };
	Element e2 = { 1001, "数据结构", 65.9 };
	Element e3 = { 1002, "java语言设计", 52.5 };
	Element e4 = { 1003, "计算机网络", 75.9 };
	SqListInsert(&sl, 1, &e1);
	SqListInsert(&sl, 2, &e2);
	SqListInsert(&sl, 3, &e3);
	SqListInsert(&sl, 5, &e3);	// 插入位置不合法，插入失败
	// 打印顺序表中的元素
	SqListPrint(&sl);

	// 销毁顺序表
	SqListDestory(&sl);
}

// 测试尾插和头插
void TestSqList3()
{
	SqList sl;
	// 初始化顺序表
	SqListInit(&sl);

	Element e1 = { 1000, "C语言程序设计", 79.9 };
	Element e2 = { 1001, "数据结构", 65.9 };
	Element e3 = { 1002, "java语言设计", 52.5 };
	Element e4 = { 1003, "计算机网络", 75.9 };
	
	// 尾插
	SqListPushBack(&sl, &e1);
	SqListPushBack(&sl, &e2);
	
	// 头插
	SqListPushFront(&sl, &e3);
	SqListPushFront(&sl, &e4);

	// 打印顺序表中的元素
	SqListPrint(&sl);
	printf("=============================================\n");

	// 顺序表删除（删除指定位置的元素） 
	SqListDelete(&sl, 3); 
	SqListDelete(&sl, 3);
	SqListDelete(&sl, 3);
	SqListPrint(&sl);

	// 销毁顺序表
	SqListDestory(&sl);
}

// 测试尾部删除和头部删除
void TestSqList4()
{
	SqList sl;
	// 初始化顺序表
	SqListInit(&sl);

	Element e1 = { 1000, "C语言程序设计", 79.9 };
	Element e2 = { 1001, "数据结构", 65.9 };
	Element e3 = { 1002, "java语言设计", 52.5 };
	Element e4 = { 1003, "计算机网络", 75.9 };
	SqListInsert(&sl, 1, &e1);
	SqListInsert(&sl, 2, &e2);
	SqListInsert(&sl, 3, &e3);
	SqListInsert(&sl, 4, &e4);	
	// 打印顺序表中的元素
	SqListPrint(&sl);

	printf("=============================================\n");
	// 头部删除
	SqListPopFront(&sl);
	SqListPrint(&sl);
	printf("=============================================\n");
	// 尾部删除
	SqListPopBack(&sl);
	SqListPrint(&sl);

	// 销毁顺序表
	SqListDestory(&sl);
}

// 测试查找
void TestSqList5()
{
	SqList sl;
	// 初始化顺序表
	SqListInit(&sl);

	Element e1 = { 1000, "C语言程序设计", 79.9 };
	Element e2 = { 1001, "数据结构", 65.9 };
	Element e3 = { 1002, "java语言设计", 52.5 };
	Element e4 = { 1003, "计算机网络", 75.9 };
	SqListInsert(&sl, 1, &e1);
	SqListInsert(&sl, 2, &e2);
	SqListInsert(&sl, 3, &e3);
	SqListInsert(&sl, 4, &e4);
	// 打印顺序表中的元素
	SqListPrint(&sl);

	printf("=============================================\n");
	int ret = SqListFind(&sl, 1002);
	if (ret)
	{
		printf("查找的元素位置：%d\n", ret);
	}
	else
	{
		printf("未找到该元素\n");
	}

	// 销毁顺序表
	SqListDestory(&sl);
}

int main()
{
	//TestSqList2();

	//TestSqList3();

	//TestSqList4();

	TestSqList5();

	return 0;
}