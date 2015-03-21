#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	stack st = createStack();
	push_stack(1, &st);
	push_stack(2, &st);
	push_stack(3, &st);
	displayStack(&st);
	pop_stack(&st);
	displayStack(&st);
	return 0;
}