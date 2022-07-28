#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct Stack
{
	ElementType *a;
	int top;		// 栈顶的位置
	int capacity;  // 实际空间大小
}Stack;

void StackInit(Stack *ps);
void StackDestroy(Stack *ps);
void StackPush(Stack *ps, ElementType val);
void StackPop(Stack *ps);
ElementType StackTop(Stack *ps);  // 取栈顶的数据
int StackSize(Stack *ps);
bool StackEmpty(Stack *ps);


