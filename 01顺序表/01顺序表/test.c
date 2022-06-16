#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"

// ����β���βɾ
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

// ����ͷ���ͷɾ
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

// ����SqListFind
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


// ������ָ��λ�ò���
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

	// ��4��λ�ò���40
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


// ����ɾ��posλ�õ�����
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

	// ˳���ĵ�ǰ����
	int len = GetLength(&sl);
	printf("len = %d\n", len);
	
	// ɾ����һ��λ�õ�Ԫ��
	SqListErase(&sl, 1);
	SqListPrint(&sl);

	// ɾ��˳����е�5
	int index = SqListFind(&sl, 5);
	if (index != -1)
	{
		SqListErase(&sl, index + 1);
	}
	SqListPrint(&sl);

	// ˳���ĵ�ǰ����
	len = GetLength(&sl);
	printf("len = %d\n", len);

	// ˳����Ƿ�Ϊ��
	int ret = isEmpty(&sl);
	printf("˳����Ƿ�Ϊ�գ�%d\n", ret);

	SqListDestory(&sl);
}


// ���Ի�ȡָ��λ��Ԫ��
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
		printf("Ҫ��ȡԪ�ص�λ�ò��Ϸ���\n");
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
