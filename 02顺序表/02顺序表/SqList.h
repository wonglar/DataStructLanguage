#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 4

// Ԥ���庯�����ؽ��
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
	Element* elem;	// ˳���Ļ���ַ
	int length;		// ��ЧԪ�ظ���
	int capacity;	// ʵ�ʿռ��С
}SqList;


// ��ʼ��˳���
Status SqListInit(SqList* ps);

// β������
Status SqListPushBack(SqList* ps, Element* e);

// ˳����ӡ
void SqListPrint(SqList* ps);


