#define _CRT_SECURE_NO_WARNINGS 1

#include "SqList.h"

void TestSqList1()
{
	SqList sl;
	// ��ʼ��˳���
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
	

	// ����λ�û�ȡ��Ӧλ������Ԫ�ص�����
	Element e;
	int ret = SqListGetElem(&sl, 3, &e);
	if (ret)
	{
		printf("%d %s %lf\n", e.bid, e.bname, e.bprice);
	}
	else
	{
		printf("Ҫ��ȡ��Ԫ��λ�ò�����!\n");
	}




	// ����˳���
	SqListDestory(&sl);
}

// ����˳�����루��ָ��λ�ò��룩
void TestSqList2()
{
	SqList sl;
	// ��ʼ��˳���
	SqListInit(&sl);

	Element e1 = { 1000, "C���Գ������", 79.9 };
	Element e2 = { 1001, "���ݽṹ", 65.9 };
	Element e3 = { 1002, "java�������", 52.5 };
	Element e4 = { 1003, "���������", 75.9 };
	SqListInsert(&sl, 1, &e1);
	SqListInsert(&sl, 2, &e2);
	SqListInsert(&sl, 3, &e3);
	SqListInsert(&sl, 5, &e3);	// ����λ�ò��Ϸ�������ʧ��
	// ��ӡ˳����е�Ԫ��
	SqListPrint(&sl);

	// ����˳���
	SqListDestory(&sl);
}

// ����β���ͷ��
void TestSqList3()
{
	SqList sl;
	// ��ʼ��˳���
	SqListInit(&sl);

	Element e1 = { 1000, "C���Գ������", 79.9 };
	Element e2 = { 1001, "���ݽṹ", 65.9 };
	Element e3 = { 1002, "java�������", 52.5 };
	Element e4 = { 1003, "���������", 75.9 };
	
	// β��
	SqListPushBack(&sl, &e1);
	SqListPushBack(&sl, &e2);
	
	// ͷ��
	SqListPushFront(&sl, &e3);
	SqListPushFront(&sl, &e4);

	// ��ӡ˳����е�Ԫ��
	SqListPrint(&sl);
	printf("=============================================\n");

	// ˳���ɾ����ɾ��ָ��λ�õ�Ԫ�أ� 
	SqListDelete(&sl, 3); 
	SqListDelete(&sl, 3);
	SqListDelete(&sl, 3);
	SqListPrint(&sl);

	// ����˳���
	SqListDestory(&sl);
}

// ����β��ɾ����ͷ��ɾ��
void TestSqList4()
{
	SqList sl;
	// ��ʼ��˳���
	SqListInit(&sl);

	Element e1 = { 1000, "C���Գ������", 79.9 };
	Element e2 = { 1001, "���ݽṹ", 65.9 };
	Element e3 = { 1002, "java�������", 52.5 };
	Element e4 = { 1003, "���������", 75.9 };
	SqListInsert(&sl, 1, &e1);
	SqListInsert(&sl, 2, &e2);
	SqListInsert(&sl, 3, &e3);
	SqListInsert(&sl, 4, &e4);	
	// ��ӡ˳����е�Ԫ��
	SqListPrint(&sl);

	printf("=============================================\n");
	// ͷ��ɾ��
	SqListPopFront(&sl);
	SqListPrint(&sl);
	printf("=============================================\n");
	// β��ɾ��
	SqListPopBack(&sl);
	SqListPrint(&sl);

	// ����˳���
	SqListDestory(&sl);
}

// ���Բ���
void TestSqList5()
{
	SqList sl;
	// ��ʼ��˳���
	SqListInit(&sl);

	Element e1 = { 1000, "C���Գ������", 79.9 };
	Element e2 = { 1001, "���ݽṹ", 65.9 };
	Element e3 = { 1002, "java�������", 52.5 };
	Element e4 = { 1003, "���������", 75.9 };
	SqListInsert(&sl, 1, &e1);
	SqListInsert(&sl, 2, &e2);
	SqListInsert(&sl, 3, &e3);
	SqListInsert(&sl, 4, &e4);
	// ��ӡ˳����е�Ԫ��
	SqListPrint(&sl);

	printf("=============================================\n");
	int ret = SqListFind(&sl, 1002);
	if (ret)
	{
		printf("���ҵ�Ԫ��λ�ã�%d\n", ret);
	}
	else
	{
		printf("δ�ҵ���Ԫ��\n");
	}

	// ����˳���
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