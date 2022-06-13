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

// 销毁顺序表
void SqListDestory(SqList* ps)
{
	if (ps != NULL)
	{
		free(ps->elem);
		ps->elem = NULL;
		ps->capacity = ps->length = 0;
	}
}


// 清空顺序表 
void SqListClear(SqList* ps)
{
	ps->length = 0; // 将顺序表的长度置为0
}

// 求顺序表的长度
int SqListGetLength(SqList* ps)
{
	return ps->length;
}

// 顺序表是否为空
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

// 顺序表取值（根据pos位置获取相应位置数据元素的内容）
int SqListGetElem(SqList* ps, int pos, Element* e)
{
	// 判断pos是否合理，不合理返回0
	if (pos < 1 || pos > ps->length)
	{
		return ERROR;
	}
	*e = ps->elem[pos - 1];

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

// 顺序表扩容
void SqListCheckCapacity(SqList* ps)
{
	if (ps->length == ps->capacity)
	{
		int newcapacity = ps->length * INCREMENT;	// 容量进行倍增
		Element* tmp = (Element*)realloc(ps->elem, sizeof(Element) * newcapacity);

		// 空间扩容失败
		if (NULL == tmp)
		{
			printf("realloc fail\n");
			exit(OVERFLOW);
		}

		// 扩容成功
		ps->elem = tmp;
		ps->capacity = newcapacity;
	}
}

// 顺序表插入（在指定位置插入）
Status SqListInsert(SqList* ps, int pos, Element* e)
{
	if (pos < 1 || pos > ps->length + 1)
	{
		return ERROR;	// pos值不合法,插入位置不合法
	}

	// 检查空间是否需要扩容
	SqListCheckCapacity(ps);

	// 挪动数据
	int i = 0;
	for (i = ps->length - 1; i >= pos - 1; i--)
	{
		ps->elem[i + 1] = ps->elem[i];
	}

	// 进行插入
	ps->elem[pos - 1] = *e;
	ps->length++;

	return OK;

}

// 尾部插入
Status SqListPushBack(SqList* ps, Element* e)
{

	//SqListCheckCapacity(ps);
	//// 空间足够，尾部插入
	//ps->elem[ps->length].bid = e->bid;
	//strcpy(ps->elem[ps->length].bname, e->bname);
	//ps->elem[ps->length].bprice = e->bprice;
	//ps->length++;
	//return OK;

	// 尾部插入可以进行复用SqListInsert函数
	return SqListInsert(ps, ps->length + 1, e);

}

// 头部插入
Status SqListPushFront(SqList* ps, Element* e)
{
	// 头部插入也可以复用SqListInsert函数
	return SqListInsert(ps, 1, e);
}

// 顺序表删除（删除指定位置的元素） 
Status SqListDelete(SqList* ps, int pos)
{
	if (pos < 1 || pos > ps->length)
	{
		return ERROR;		// pos值不合法,插入位置不合法
	}
	int i = 0;
	for (i = pos - 1; i < ps->length - 1; i++)
	{
		ps->elem[i] = ps->elem[i+1];
	}

	ps->length--;

	return OK;
}

//尾部删除
Status SqListPopBack(SqList* ps)
{
	// 复用SqListDelete函数
	return SqListDelete(ps, ps->length);
}

//头部删除
Status SqListPopFront(SqList* ps)
{
	// 复用SqListDelete函数
	return SqListDelete(ps, 1);
}

// 顺序表的查找，在线性表中查找与指定值e相同的数据元素的位置，找到返回该元素的位置序号，未找到返回0
// 根据书号进行查找
int SqListFind(SqList* ps, int bid)
{
	int i = 0;
	for (i = 0; i < ps->length; i++)
	{
		if (ps->elem[i].bid == bid)
		{
			return i + 1;   // 找到返回位置序号
		}
	}

	// 查找失败，返回0
	return 0;
}






