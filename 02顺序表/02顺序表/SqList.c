#define _CRT_SECURE_NO_WARNINGS 1

#include "SqList.h"

// ˳����ʼ��
Status SqListInit(SqList* ps)
{
	ps->elem = (Element*)malloc(sizeof(Element) * MAX_SIZE);

	if (NULL == ps->elem)
	{
		printf("malloc fail\n");
		return OVERFLOW;
	}

	ps->length = 0;
	ps->capacity = MAX_SIZE;

	return OK;
}

// ����˳���
void SqListDestory(SqList* ps)
{
	if (ps != NULL)
	{
		free(ps->elem);
		ps->elem = NULL;
		ps->capacity = ps->length = 0;
	}
}


// ���˳��� 
void SqListClear(SqList* ps)
{
	ps->length = 0; // ��˳���ĳ�����Ϊ0
}

// ��˳���ĳ���
int SqListGetLength(SqList* ps)
{
	return ps->length;
}

// ˳����Ƿ�Ϊ��
int SqListIsEmpty(SqList* ps)
{
	if (ps->length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

// ˳���ȡֵ������posλ�û�ȡ��Ӧλ������Ԫ�ص����ݣ�
int SqListGetElem(SqList* ps, int pos, Element* e)
{
	// �ж�pos�Ƿ������������0
	if (pos < 1 || pos > ps->length)
	{
		return ERROR;
	}
	*e = ps->elem[pos - 1];

	return OK;
}

// ˳����ӡ
void SqListPrint(SqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->length; i++)
	{
		printf("%d\t%s\t%lf\n", ps->elem[i].bid, ps->elem[i].bname, ps->elem[i].bprice);
	}
}

// ˳�������
void SqListCheckCapacity(SqList* ps)
{
	if (ps->length == ps->capacity)
	{
		int newcapacity = ps->length * INCREMENT;	// �������б���
		Element* tmp = (Element*)realloc(ps->elem, sizeof(Element) * newcapacity);

		// �ռ�����ʧ��
		if (NULL == tmp)
		{
			printf("realloc fail\n");
			exit(OVERFLOW);
		}

		// ���ݳɹ�
		ps->elem = tmp;
		ps->capacity = newcapacity;
	}
}

// ˳�����루��ָ��λ�ò��룩
Status SqListInsert(SqList* ps, int pos, Element* e)
{
	if (pos < 1 || pos > ps->length + 1)
	{
		return ERROR;	// posֵ���Ϸ�,����λ�ò��Ϸ�
	}

	// ���ռ��Ƿ���Ҫ����
	SqListCheckCapacity(ps);

	// Ų������
	int i = 0;
	for (i = ps->length - 1; i >= pos - 1; i--)
	{
		ps->elem[i + 1] = ps->elem[i];
	}

	// ���в���
	ps->elem[pos - 1] = *e;
	ps->length++;

	return OK;

}

// β������
Status SqListPushBack(SqList* ps, Element* e)
{

	//SqListCheckCapacity(ps);
	//// �ռ��㹻��β������
	//ps->elem[ps->length].bid = e->bid;
	//strcpy(ps->elem[ps->length].bname, e->bname);
	//ps->elem[ps->length].bprice = e->bprice;
	//ps->length++;
	//return OK;

	// β��������Խ��и���SqListInsert����
	return SqListInsert(ps, ps->length + 1, e);

}

// ͷ������
Status SqListPushFront(SqList* ps, Element* e)
{
	// ͷ������Ҳ���Ը���SqListInsert����
	return SqListInsert(ps, 1, e);
}

// ˳���ɾ����ɾ��ָ��λ�õ�Ԫ�أ� 
Status SqListDelete(SqList* ps, int pos)
{
	if (pos < 1 || pos > ps->length)
	{
		return ERROR;		// posֵ���Ϸ�,����λ�ò��Ϸ�
	}
	int i = 0;
	for (i = pos - 1; i < ps->length - 1; i++)
	{
		ps->elem[i] = ps->elem[i+1];
	}

	ps->length--;

	return OK;
}

//β��ɾ��
Status SqListPopBack(SqList* ps)
{
	// ����SqListDelete����
	return SqListDelete(ps, ps->length);
}

//ͷ��ɾ��
Status SqListPopFront(SqList* ps)
{
	// ����SqListDelete����
	return SqListDelete(ps, 1);
}

// ˳���Ĳ��ң������Ա��в�����ָ��ֵe��ͬ������Ԫ�ص�λ�ã��ҵ����ظ�Ԫ�ص�λ����ţ�δ�ҵ�����0
// ������Ž��в���
int SqListFind(SqList* ps, int bid)
{
	int i = 0;
	for (i = 0; i < ps->length; i++)
	{
		if (ps->elem[i].bid == bid)
		{
			return i + 1;   // �ҵ�����λ�����
		}
	}

	// ����ʧ�ܣ�����0
	return 0;
}






