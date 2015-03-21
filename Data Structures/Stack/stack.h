#ifndef STACK_H
#define STACK_H

typedef struct
{
	int size;
	int *st;
}stack;

stack createStack();
void push_stack(int e, stack *s);
void pop_stack(stack *s);
void displayStack(stack *s);

#endif