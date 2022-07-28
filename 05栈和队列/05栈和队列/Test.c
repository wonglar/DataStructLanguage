#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

void StackTest01()
{
	Stack stack;
	StackInit(&stack);

	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);

	while (!StackEmpty(&stack))
	{
		printf("%d ", StackTop(&stack));
		StackPop(&stack);
	}

	StackDestroy(&stack);

}

int main()
{
	StackTest01();

	return 0;
}