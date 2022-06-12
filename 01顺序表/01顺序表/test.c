#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"

// ≤‚ ‘1
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

// ≤‚ ‘2
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

// ≤‚ ‘3
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


// ≤‚ ‘4
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

	// ‘⁄4µƒŒª÷√≤Â»Î40
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

int main()
{

	 TestSqList1();

	 //TestSqList2();

	//TestSqList3();

	// TestSqList4();

	return 0;
}
