#define _CRT_SECURE_NO_WARNINGS

#include "SqList.h"

// 扩容
void SqListCheckCapacity(SqList* ps)
{
	// 如果没有空间，或者空间不足，进行扩容
	if (ps->length == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? MAX_SIZE : ps->capacity * 2;
		ElemType* tmp = (ElemType*)realloc(ps->elem, newcapacity * sizeof(ElemType));

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
}

// 打印顺序表
void SqListPrint(SqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->length; i++)
	{
		printf("%d ", ps->elem[i]);
	}
	printf("\n");
}

// 初始化顺序表
void SqListInit(SqList* ps)
{
	ps->elem = NULL;
	ps->length = 0;
	ps->capacity = 0;
}

// 销毁顺序表
void SqListDestory(SqList* ps)
{
	free(ps->elem);
	ps->elem = NULL;
	ps->capacity = ps->length = 0;
}

// 尾部插入
void SqListPushBack(SqList* ps, ElemType e)
{
	//// 如果没有空间，或者空间不足，进行扩容
	//SqListCheckCapacity(ps);
	//
	//// 空间足够，直接尾部插入
	//ps->elem[ps->length] = e;
	//ps->length++;

	SqListInsert(ps, ps->length + 1, e);
}

// 尾部删除
void SqListPopBack(SqList* ps)
{
	// ps->elem[ps->length - 1] = 0;  // 这里没有必要置为0，因为length是标识有效数据的个数，ps->length-- 就可以访问不到了
	

	// 方式一：温柔处理方式
	//if (ps->length > 0)
	//{
	//	ps->length--;
	//}

	//// 方式二：暴力处理方式
	//assert(ps->length > 0);
	//ps->length--;


	// 尾删复用
	SqListErase(ps, ps->length);

}

// 头部插入
void SqListPushFront(SqList* ps, ElemType e)
{
	//// 如果没有空间，或者空间不足，进行扩容
	//SqListCheckCapacity(ps);

	//// 挪动数据
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

// 头部删除
void SqListPopFront(SqList* ps)
{
	//// 有数据才删
	//assert(ps->length > 0);

	//// 挪动数据
	//int begin = 1;
	//while (begin < ps->length)
	//{
	//	ps->elem[begin - 1] = ps->elem[begin];
	//	begin++;
	//}
	//
	//ps->length--;

	// 头删复用
	SqListErase(ps, 1);

}


// 找到了返回e位置下标，没有找到返回-1
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

// 指定的位置插入
void SqListInsert(SqList* ps, int pos, ElemType e)
{
	// 温柔的处理方式
	//if (pos > ps->length + 1 || pos < 1)  // 注意：pos为位序，不是下标
	//{
	//	printf("pos invalid\n");   
	//	return;
	//}

	// 粗暴的处理方式
	assert(pos >= 1 && pos <= ps->length + 1);

	// 空间不足，进行增容
	SqListCheckCapacity(ps);

	// 挪动数据
	int i = 0;
	for (i = ps->length - 1; i >= pos - 1; i--)
	{
		ps->elem[i + 1] = ps->elem[i];
	}
	
	ps->elem[pos - 1] = e;
	ps->length++;

}

// 删除pos位置的数据 注意此处pos也是位序，不是数组的下标
void SqListErase(SqList* ps, int pos)
{
	// 处理删除的位置不合法
	assert(pos >= 1 && pos <= ps->length);


	while (pos < ps->length)
	{
		ps->elem[pos - 1] = ps->elem[pos];
		pos++;
	}

	ps->length--;

}