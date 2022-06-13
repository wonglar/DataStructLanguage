#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 3

// 预定义函数返回结果
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INCREMENT 2  

typedef int Status;

typedef struct Book
{
	int bid;			// 图书id
	char bname[30];		// 图书名称
	double bprice;		// 图书价格
}Element;

typedef struct SqList
{
	Element* elem;	// 顺序表的基地址
	int length;		// 有效元素个数
	int capacity;	// 实际空间大小
}SqList;


// 初始化顺序表
Status SqListInit(SqList* ps);

// 销毁线性表
void SqListDestory(SqList* ps);

// 清空顺序表 
void SqListClear(SqList* ps);

// 求顺序表的长度
int SqListGetLength(SqList* ps);

// 顺序表是否为空
int SqListIsEmpty(SqList* ps);

// 顺序表打印
void SqListPrint(SqList* ps);

// 顺序表取值（根据pos位置获取相应位置数据元素的内容）
int SqListGetElem(SqList* ps, int pos, Element* e);

// 顺序表扩容
void SqListCheckCapacity(SqList* ps);

// 顺序表插入（在指定位置插入）
Status SqListInsert(SqList* ps, int pos, Element* e);

// 尾部插入
Status SqListPushBack(SqList* ps, Element* e);

// 头部插入
Status SqListPushFront(SqList* ps, Element* e);

// 顺序表删除（删除指定位置的元素） 
Status SqListDelete(SqList* ps, int pos);

//尾部删除
Status SqListPopBack(SqList* ps);

//头部删除
Status SqListPopFront(SqList* ps);

// 顺序表的查找，在线性表中查找与指定值e相同的数据元素的位置，找到返回该元素的位置序号，未找到返回0
// 根据书号进行查找
int SqListFind(SqList* ps, int bid);






