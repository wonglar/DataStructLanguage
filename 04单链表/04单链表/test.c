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

void TestList02()
{


}


void TestList03()
{


}


void TestList04()
{


}


void TestList05()
{


}


void TestList06()
{


}


void TestList07()
{


}


void TestList08()
{


}


void TestList09()
{


}


void TestList10()
{


}


void TestList11()
{


}


void TestList12()
{


}

void TestList13()
{


}

int main()
{
	TestList01();

	return 0;
}