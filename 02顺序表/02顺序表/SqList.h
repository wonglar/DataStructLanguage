#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 4

// 预定义函数返回结果
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct Book
{
	int bid;
	char bname[30];
	double bprice;
}Element;

typedef struct SqList
{
	Element* elem;	// 顺序表的基地址
	int length;		// 有效元素个数
	int capacity;	// 实际空间大小
}SqList;


// 初始化顺序表
Status SqListInit(SqList* ps);

// 尾部插入
Status SqListPushBack(SqList* ps, Element* e);

// 顺序表打印
void SqListPrint(SqList* ps);


