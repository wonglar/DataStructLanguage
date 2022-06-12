#define _CRT_SECURE_NO_WARNINGS

#include "SqList.h"

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

// 尾部插入
void SqListPushBack(SqList* ps, ElemType e)
{
	// 如果没有空间，或者空间不足，进行扩容
	if (ps->length == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? MAX_SIZE : ps->capacity * 2;
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

// 销毁顺序表
void SqListDestory(SqList* ps)
{
	free(ps->elem);
	ps->elem = NULL;
	ps->capacity = ps->length = 0;
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

	// 方式二：暴力处理方式
	assert(ps->length > 0);
	ps->length--;

}

// 头部插入
void SqListPushFront(SqList* ps, ElemType e)
{
	// 挪动数据
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