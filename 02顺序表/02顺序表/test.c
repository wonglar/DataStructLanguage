#define _CRT_SECURE_NO_WARNINGS 1

#include "SqList.h"

void TestSqList1()
{
	SqList sl;
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
}


int main()
{
	TestSqList1();

	return 0;
}