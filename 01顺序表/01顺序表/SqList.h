#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*

#define MAX_SIZE 50
typedef int ElemType;


// ��̬˳���
// ��̬�ص㣺������˾Ͳ��ò��룬  ȱ�㣺�����ٿռ���ʣ� ����Ƚ���ȷ������С�˲����ã��������˷ѣ�
typedef struct SqList
{
	ElemType elem[MAX_SIZE];
	int length;	// ˳�����ЧԪ�ظ���
}SqList;


void SqListInit(SqList* list);
void SqListPushBack(SqList* list, ElemType e);
void SqListPopBack(SqList* list);
void SqListPushFront(SqList* list, ElemType e);
void SqListPopFront(SqList* list);


*/

#define MAX_SIZE 4
typedef int ElemType;

// ��̬˳���
typedef struct SqList
{
	ElemType* elem;
	int length;	// ˳�����ЧԪ�ظ���
	int capacity; // ����ʵ�ʵ�����
}SqList;

// ��ӡ˳���
void SqListPrint(SqList* ps);
// ��ʼ��˳���
void SqListInit(SqList* ps);
// ����˳���
void SqListDestory(SqList* ps);
// ����
void SqListCheckCapacity(SqList* ps);
// �õ�˳���ĳ���
int GetLength(SqList* ps);
// �ж�˳����Ƿ�Ϊ�գ�Ϊ�շ���1���ǿշ���0
int isEmpty(SqList* ps);
// ˳���ȡֵ������λ��pos����ȡ��Ӧλ������Ԫ�ص����ݣ� ע�⣺pos��λ�򣬲������������
int GetElem(SqList* ps, int pos, ElemType* e);


// β������
void SqListPushBack(SqList* ps, ElemType e);
// β��ɾ��
void SqListPopBack(SqList* ps);
// ͷ������
void SqListPushFront(SqList* ps, ElemType e);
// ͷ��ɾ��
void SqListPopFront(SqList* ps);

// �ҵ��˷���eλ���±꣬û���ҵ�����-1
int SqListFind(SqList* ps, ElemType e);
// ָ����λ�ò���
void SqListInsert(SqList* ps, int pos, ElemType e);
// ɾ��posλ�õ�����
void SqListErase(SqList* ps, int pos);