#define _CRT_SECURE_NO_WARNINGS

#include "SqList.h"

void SqListPrint(SqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->length; i++)
	{
		printf("%d ", ps->elem[i]);
	}
	printf("\n");
}


void SqListInit(SqList* ps)
{
	ps->elem = NULL;
	ps->length = 0;
	ps->capacity = 0;
}


void SqListPushBack(SqList* ps, ElemType e)
{
	// 如果没有空间，或者空间不足，进行扩容
	if (ps->length == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
		ElemType* tmp = (ElemType*)realloc(ps->elem ,newcapacity * sizeof(ElemType));

		// 空间开辟失败
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		// 空间开辟成功
		ps->elem = tmp;
		ps->capacity = newcapacity;

	}

	// 空间足够，直接尾部插入
	ps->elem[ps->length] = e;
	ps->length++;


}



void SqListPopBack(SqList* ps);
void SqListPushFront(SqList* ps, ElemType e);
void SqListPopFront(SqList* ps);