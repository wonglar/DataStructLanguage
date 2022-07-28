#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"


void StackInit(Stack *ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;	// 也可以给-1；初始给0意味着指向的是栈顶元素的下一个
	ps->capacity = 0;
}

void StackDestroy(Stack *ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(Stack *ps, ElementType val)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ElementType *tmp = realloc(ps->a, sizeof(Stack) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	ps->a[ps->top] = val;
	ps->top++;
}

void StackPop(Stack *ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

// 取栈顶元素
ElementType StackTop(Stack *ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

int StackSize(Stack *ps)
{
	assert(ps);

	return ps->top;

}

bool StackEmpty(Stack *ps)
{
	assert(ps);

	return ps->top == 0;
}
