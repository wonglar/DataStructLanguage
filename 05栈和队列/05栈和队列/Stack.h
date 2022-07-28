#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct Stack
{
	ElementType *a;
	int top;		// ջ����λ��
	int capacity;  // ʵ�ʿռ��С
}Stack;

void StackInit(Stack *ps);
void StackDestroy(Stack *ps);
void StackPush(Stack *ps, ElementType val);
void StackPop(Stack *ps);
ElementType StackTop(Stack *ps);  // ȡջ��������
int StackSize(Stack *ps);
bool StackEmpty(Stack *ps);


