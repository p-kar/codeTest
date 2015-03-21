#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

stack createStack()
{
	stack s;
	s.size = 0;
	s.st = NULL;
	return s;
}

void push_stack(int e, stack *s)
{
	s->size++;
	s->st = (int*) realloc(s->st, s->size * sizeof(int));
	s->st[s->size - 1] = e;
}

void pop_stack(stack *s)
{
	if(s->size == 0)
	{
		printf("UNDERFLOW\n");
		return;
	}
	s->size--;
	s->st = (int*) realloc(s->st, s->size * sizeof(int));
}

void displayStack(stack *s)
{
	printf("TOP ");
	int i;
	for (i = 0; i < s->size; ++i)
		printf("%d ", s->st[s->size - i - 1]);
	printf("\n");
}