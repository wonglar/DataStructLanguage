#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"

void TestSqList1()
{
	SqList sl;
	SqListInit(&sl);
	SqListPopBack(&sl, 1);
	SqListPopBack(&sl, 2);
	SqListPopBack(&sl, 3);
	SqListPopBack(&sl, 4);
	SqListPopBack(&sl, 5);
}


int main()
{
	TestSqList1();

	return 0;
}
