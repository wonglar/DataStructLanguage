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
}


int main()
{
	TestSqList1();

	return 0;
}
