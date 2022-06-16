#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 3

// Ԥ���庯�����ؽ��
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INCREMENT 2  

typedef int Status;

typedef struct Book
{
	int bid;			// ͼ��id
	char bname[30];		// ͼ������
	double bprice;		// ͼ��۸�
}Element;

typedef struct SqList
{
	Element* elem;	// ˳���Ļ���ַ
	int length;		// ��ЧԪ�ظ���
	int capacity;	// ʵ�ʿռ��С
}SqList;


// ��ʼ��˳���
Status SqListInit(SqList* ps);

// �������Ա�
void SqListDestory(SqList* ps);

// ���˳��� 
void SqListClear(SqList* ps);

// ��˳���ĳ���
int SqListGetLength(SqList* ps);

// ˳����Ƿ�Ϊ��
int SqListIsEmpty(SqList* ps);

// ˳����ӡ
void SqListPrint(SqList* ps);

// ˳���ȡֵ������posλ�û�ȡ��Ӧλ������Ԫ�ص����ݣ�
int SqListGetElem(SqList* ps, int pos, Element* e);

// ˳�������
void SqListCheckCapacity(SqList* ps);

// ˳�����루��ָ��λ�ò��룩
Status SqListInsert(SqList* ps, int pos, Element* e);

// β������
Status SqListPushBack(SqList* ps, Element* e);

// ͷ������
Status SqListPushFront(SqList* ps, Element* e);

// ˳���ɾ����ɾ��ָ��λ�õ�Ԫ�أ� 
Status SqListDelete(SqList* ps, int pos);

//β��ɾ��
Status SqListPopBack(SqList* ps);

//ͷ��ɾ��
Status SqListPopFront(SqList* ps);

// ˳���Ĳ��ң������Ա��в�����ָ��ֵe��ͬ������Ԫ�ص�λ�ã��ҵ����ظ�Ԫ�ص�λ����ţ�δ�ҵ�����0
// ������Ž��в���
int SqListFind(SqList* ps, int bid);






