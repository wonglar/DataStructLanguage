#define _CRT_SECURE_NO_WARNINGS

#include "SqList.h"

void SqListInit(SqList* ps)
{
	ps->elem = NULL;
	ps->length = 0;
	ps->capacity = 0;
}


void SqListPushBack(SqList* ps, ElemType e)
{
	if (ps->length == ps->capacity)
	{

	}

	// �ռ��㹻��ֱ��β������
	ps->elem[ps->length] = e;
	ps->length++;


}



void SqListPopBack(SqList* ps);
void SqListPushFront(SqList* ps, ElemType e);
void SqListPopFront(SqList* ps);