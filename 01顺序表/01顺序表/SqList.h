#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*

#define MAX_SIZE 50
typedef int ElemType;


// 静态顺序表
// 静态特点：如果满了就不让插入，  缺点：给多少空间合适？ 这个比较难确定（给小了不够用，给大了浪费）
typedef struct SqList
{
	ElemType elem[MAX_SIZE];
	int length;	// 顺序表有效元素个数
}SqList;


void SqListInit(SqList* list);
void SqListPushBack(SqList* list, ElemType e);
void SqListPopBack(SqList* list);
void SqListPushFront(SqList* list, ElemType e);
void SqListPopFront(SqList* list);


*/

#define MAX_SIZE 4
typedef int ElemType;

// 动态顺序表
typedef struct SqList
{
	ElemType* elem;
	int length;	// 顺序表有效元素个数
	int capacity; // 数组实际的容量
}SqList;

// 打印顺序表
void SqListPrint(SqList* ps);
// 初始化顺序表
void SqListInit(SqList* ps);
// 销毁顺序表
void SqListDestory(SqList* ps);
// 扩容
void SqListCheckCapacity(SqList* ps);
// 尾部删除
void SqListPopBack(SqList* ps);
// 尾部插入
void SqListPushBack(SqList* ps, ElemType e);
// 头部插入
void SqListPushFront(SqList* ps, ElemType e);
// 头部删除
void SqListPopFront(SqList* ps);

// 找到了返回e位置下标，没有找到返回-1
int SqListFind(SqList* ps, ElemType e);
// 指定的位置插入
void SqListInsert(SqList* ps, int pos, ElemType e);
// 删除pos位置的数据
void SqListErase(SqList* ps, int pos);