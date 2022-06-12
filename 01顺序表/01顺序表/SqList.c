#define _CRT_SECURE_NO_WARNINGS

#include "SqList.h"

// ����
void SqListCheckCapacity(SqList* ps)
{
	// ���û�пռ䣬���߿ռ䲻�㣬��������
	if (ps->length == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? MAX_SIZE : ps->capacity * 2;
		ElemType* tmp = (ElemType*)realloc(ps->elem, newcapacity * sizeof(ElemType));

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
}

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

// ����˳���
void SqListDestory(SqList* ps)
{
	free(ps->elem);
	ps->elem = NULL;
	ps->capacity = ps->length = 0;
}

// β������
void SqListPushBack(SqList* ps, ElemType e)
{
	//// ���û�пռ䣬���߿ռ䲻�㣬��������
	//SqListCheckCapacity(ps);
	//
	//// �ռ��㹻��ֱ��β������
	//ps->elem[ps->length] = e;
	//ps->length++;

	SqListInsert(ps, ps->length + 1, e);
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

	//// ��ʽ������������ʽ
	//assert(ps->length > 0);
	//ps->length--;


	// βɾ����
	SqListErase(ps, ps->length);

}

// ͷ������
void SqListPushFront(SqList* ps, ElemType e)
{
	//// ���û�пռ䣬���߿ռ䲻�㣬��������
	//SqListCheckCapacity(ps);

	//// Ų������
	//int end = ps->length - 1;
	//while (end >= 0)
	//{
	//	ps->elem[end + 1] = ps->elem[end];
	//	end--;
	//}

	//ps->elem[0] = e;
	//ps->length++;

	SqListInsert(ps, 1, e);

}

// ͷ��ɾ��
void SqListPopFront(SqList* ps)
{
	//// �����ݲ�ɾ
	//assert(ps->length > 0);

	//// Ų������
	//int begin = 1;
	//while (begin < ps->length)
	//{
	//	ps->elem[begin - 1] = ps->elem[begin];
	//	begin++;
	//}
	//
	//ps->length--;

	// ͷɾ����
	SqListErase(ps, 1);

}


// �ҵ��˷���eλ���±꣬û���ҵ�����-1
int SqListFind(SqList* ps, ElemType e)
{
	int i = 0;
	for (i = 0; i < ps->length; i++)
	{
		if (ps->elem[i] == e)
		{
			return i;
		}
	}

	return -1;
}

// ָ����λ�ò���
void SqListInsert(SqList* ps, int pos, ElemType e)
{
	// ����Ĵ���ʽ
	//if (pos > ps->length + 1 || pos < 1)  // ע�⣺posΪλ�򣬲����±�
	//{
	//	printf("pos invalid\n");   
	//	return;
	//}

	// �ֱ��Ĵ���ʽ
	assert(pos >= 1 && pos <= ps->length + 1);

	// �ռ䲻�㣬��������
	SqListCheckCapacity(ps);

	// Ų������
	int i = 0;
	for (i = ps->length - 1; i >= pos - 1; i--)
	{
		ps->elem[i + 1] = ps->elem[i];
	}
	
	ps->elem[pos - 1] = e;
	ps->length++;

}

// ɾ��posλ�õ����� ע��˴�posҲ��λ�򣬲���������±�
void SqListErase(SqList* ps, int pos)
{
	// ����ɾ����λ�ò��Ϸ�
	assert(pos >= 1 && pos <= ps->length);


	while (pos < ps->length)
	{
		ps->elem[pos - 1] = ps->elem[pos];
		pos++;
	}

	ps->length--;

}