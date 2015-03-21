#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int arr1[10] = {8, 9, 4, 5, 1, 2, 6, 3, 0, 7};
	int pos;
	scanf("%d", &pos);
	printf("%d\n", kthSmallest(arr1, 0, 9, pos));
	quickSort(arr1, 10);
	displayArray(arr1, 10);
	return 0;
}