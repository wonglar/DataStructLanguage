#define _CRT_SECURE_NO_WARNINGS 1
#include "SingleList.h"

// ���Գ�ʼ�����пա����١����
void TestList01()
{
	LinkList list;
	// ��ʼ��������
	ListInit(&list);

	int ret = ListEmpty(list);
	if (ret)
	{
		printf("����Ϊ�գ�\n");
	}
	else
	{
		printf("����ǿգ�\n");
	}

	ListDestroy(&list);

	ListClear(&list);

}

// ����ָ��λ�ò��룬�ڵ�pos���ڵ�λ�ò���һ���½ڵ�
void TestList02()
{
	LinkList list;
	// ��ʼ��������
	ListInit(&list);

	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	ListInsert(&list, 3, 3);
	ListInsert(&list, 4, 4);
	ListPrint(list);

}

// ���԰�ֵ���Һ�ȡ��pos��Ԫ��ֵ
void TestList03()
{
	LinkList list;
	// ��ʼ��������
	ListInit(&list);

	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	ListInsert(&list, 3, 3);
	ListInsert(&list, 4, 4);
	ListPrint(list);

	ListNode* p = ListSearchByVal(list, 3);
	if (p != NULL)
	{
		printf("%d\n", p->data);
	}
	else
	{
		printf("δ�ҵ���ֵ��\n");
	}

	int pos = ListSearchByVal_pos(list, 1);
	if (pos)
	{
		printf("%d\n", pos);
	}
	else
	{
		printf("δ�ҵ���ֵ��λ�ã�\n");
	}

	ElementType e;
	int ret = ListGetElem(list, 3, &e);
	if (ret)
	{
		printf("e = %d\n", e);
	}
}


void TestList04()
{

	LinkList list;
	// ��ʼ��������
	ListInit(&list);

	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	ListInsert(&list, 3, 3);
	ListInsert(&list, 4, 4);
	ListPrint(list);

	ElementType e;
	ListDeleteByPos(&list, 3, &e);
	ListPrint(list);
	printf("ɾ����Ԫ���ǣ�%d\n", e);
}


void TestList05()
{
	LinkList list;
	CreatList_H(&list, 5);
	ListPrint(list);

}


void TestList06()
{
	LinkList list;
	CreatList_T(&list, 5);
	ListPrint(list);

}


int main()
{
	TestList06();

	return 0;
}