#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

void TestSList1()
{

	SLTNode* plist = NULL;
	// β������
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	
	SListPrint(plist);

	// ͷ������
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

}

void TestSList2()
{

	SLTNode* plist = NULL;

	// ͷ������
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);

}


void TestSList3()
{

	SLTNode* plist = NULL;

	// β������
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	// β��ɾ��
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);



	SListPrint(plist);
}

void TestSList4()
{

	SLTNode* plist = NULL;

	// β������
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	// ͷ��ɾ��
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);


	SListPrint(plist);
}


void TestSList5()
{

	SLTNode* plist = NULL;

	// β������
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 4);

	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 2);
	int i = 1;
	while (pos)
	{
		printf("��%d��pos�ڵ�:%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	// SListFind���������޸�
	// �޸�3Ϊ30
	pos = SListFind(plist, 3);
	if (pos)
	{
		pos->data = 30;
	}

	SListPrint(plist);
}

void TestSList6()
{

	SLTNode* plist = NULL;

	// β������
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}

	SListPrint(plist);

	pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 10);
	}

	SListPrint(plist);
}

//int main()
//{
//	//TestSList1();
//	//TestSList2();
//
//	//TestSList3();
//
//	//TestSList4();
//
//	//TestSList5();
//
//	TestSList6();
//
//	return 0;
//}