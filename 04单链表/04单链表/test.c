#define _CRT_SECURE_NO_WARNINGS 1
#include "SingleList.h"

// 测试初始化、判空、销毁、清空
void TestList01()
{
	LinkList list;
	// 初始化单链表
	ListInit(&list);

	int ret = ListEmpty(list);
	if (ret)
	{
		printf("链表为空！\n");
	}
	else
	{
		printf("链表非空！\n");
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