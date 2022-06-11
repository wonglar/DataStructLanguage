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
	// ���û�пռ䣬���߿ռ䲻�㣬��������
	if (ps->length == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
		ElemType* tmp = (ElemType*)realloc(ps->elem ,newcapacity * sizeof(ElemType));

		// �ռ俪��ʧ��
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		// �ռ俪�ٳɹ�
		ps->elem = tmp;
		ps->capacity = newcapacity;

	}

	// �ռ��㹻��ֱ��β������
	ps->elem[ps->length] = e;
	ps->length++;


}



void SqListPopBack(SqList* ps);
void SqListPushFront(SqList* ps, ElemType e);
void SqListPopFront(SqList* ps);