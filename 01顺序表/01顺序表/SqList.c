#define _CRT_SECURE_NO_WARNINGS

#include "SqList.h"

// ��ӡ˳���
void SqListPrint(SqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->length; i++)
	{
		printf("%d ", ps->elem[i]);
	}
	printf("\n");
}

// ��ʼ��˳���
void SqListInit(SqList* ps)
{
	ps->elem = NULL;
	ps->length = 0;
	ps->capacity = 0;
}

// β������
void SqListPushBack(SqList* ps, ElemType e)
{
	// ���û�пռ䣬���߿ռ䲻�㣬��������
	if (ps->length == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? MAX_SIZE : ps->capacity * 2;
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

// ����˳���
void SqListDestory(SqList* ps)
{
	free(ps->elem);
	ps->elem = NULL;
	ps->capacity = ps->length = 0;
}

// β��ɾ��
void SqListPopBack(SqList* ps)
{
	// ps->elem[ps->length - 1] = 0;  // ����û�б�Ҫ��Ϊ0����Ϊlength�Ǳ�ʶ��Ч���ݵĸ�����ps->length-- �Ϳ��Է��ʲ�����
	

	// ��ʽһ�����ᴦ��ʽ
	//if (ps->length > 0)
	//{
	//	ps->length--;
	//}

	// ��ʽ������������ʽ
	assert(ps->length > 0);
	ps->length--;

}

// ͷ������
void SqListPushFront(SqList* ps, ElemType e)
{
	// Ų������
	int end = ps->length - 1;
	while (end >= 0)
	{
		ps->elem[end + 1] = ps->elem[end];
		end--;
	}

	ps->elem[0] = e;
	ps->length++;
}

void SqListPopFront(SqList* ps);