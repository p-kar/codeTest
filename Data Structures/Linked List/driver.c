#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	llist l1 = createLList();
	push_back(8, &l1);
	push_back(4, &l1);
	push_back(3, &l1);
	push_back(7, &l1);
	push_back(2, &l1);
	push_back(0, &l1);
	push_back(9, &l1);
	push_back(6, &l1);
	push_back(5, &l1);
	push_back(1, &l1);
	displayList(&l1);
	quickSortLL(&l1);
	displayList(&l1);
	return 0;
}