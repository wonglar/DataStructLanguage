#define _CRT_SECURE_NO_WARNINGS 1

#include "SqList.h"

void TestSqList1()
{
	SqList sl;
	SqListInit(&sl);

	Element e1 = { 1000, "C���Գ������", 79.9 };
	SqListPushBack(&sl, &e1);
	Element e2 = { 1001, "���ݽṹ", 65.9 };
	SqListPushBack(&sl, &e2);
	Element e3 = { 1002, "java�������", 52.5 };
	SqListPushBack(&sl, &e3);

	Element e4 = { 1003, "���������", 75.9 };
	SqListPushBack(&sl, &e4);

	Element e5 = { 1004, "����ϵͳ", 85.0 };
	SqListPushBack(&sl, &e5);


	// ��ӡ˳����е�Ԫ��
	SqListPrint(&sl);
}


int main()
{
	TestSqList1();

	return 0;
}