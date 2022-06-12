#define _CRT_SECURE_NO_WARNINGS 1

#include "SqList.h"

// 顺序表初始化
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


// 尾部插入
Status SqListPushBack(SqList* ps, Element* e)
{
	if (ps->length == ps->capacity)
	{
		int newcapacity = ps->capacity * 2;
		Element* tmp = (Element*)realloc(ps->elem, sizeof(Element) * newcapacity);


		// 空间扩容失败
		if (NULL == tmp)
		{
			printf("realloc fail\n");
			return OVERFLOW;
		}

		//扩容成功
		ps->elem = tmp;
		ps->capacity = newcapacity;

	}

	// 空间足够，尾部插入
	ps->elem[ps->length].bid = e->bid;
	strcpy(ps->elem[ps->length].bname, e->bname);
	ps->elem[ps->length].bprice = e->bprice;

	ps->length++;

	return OK;
}

// 顺序表打印
void SqListPrint(SqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->length; i++)
	{
		printf("%d\t%s\t%lf\n", ps->elem[i].bid, ps->elem[i].bname, ps->elem[i].bprice);
	}
}

