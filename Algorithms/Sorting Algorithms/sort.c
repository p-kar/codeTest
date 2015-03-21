#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void insertSort(int arr[], int size)
{
	int i, j;
	for (int i = 1; i < size; ++i)
	{
		int temp = arr[i];
		int flag = 0;
		for (int j = i-1; j > -1; --j)
		{
			if(arr[j] <= temp)
			{
				arr[j+1] = temp;
				flag = 1;
				break;
			}
			arr[j+1] = arr[j];
		}
		if(flag == 0)
			arr[0] = temp;
	}
}

void mergeSort(int arr[], int size)
{
	if(size == 1)
		return;
	int size1 = size/2;
	int size2 = size - size1;
	int arr1[size1];
	int arr2[size2];
	int cnt, cnt1;
	for (cnt = 0; cnt < size1; ++cnt)
		arr1[cnt] = arr[cnt];
	for (cnt1 = 0; cnt1 < size2; ++cnt1)
		arr2[cnt1] = arr[cnt + cnt1];
	mergeSort(arr1, size1);
	mergeSort(arr2, size2);
	int i = 0, j = 0, k = 0;
	while(i < size1 && j < size2)
	{
		if(arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = arr2[j];
			j++;
			k++;
		}
	}
	while(i < size1)
	{
		arr[k] = arr1[i];
		i++;
		k++;
	}
	while(j < size2)
	{
		arr[k] = arr2[j];
		j++;
		k++;
	}
}

void quickSort(int arr[], int size)
{
	quickSortHelper(arr, 0, size - 1);
}

void quickSortHelper(int arr[], int l, int r)
{
	if(l >= r)
		return;
	int p = partition(arr, l, r);
	quickSortHelper(arr, l, p);
	quickSortHelper(arr, p+1, r);
}

int partition(int arr[], int l, int r)
{
	int p = l;
	int i = p + 1;
	while(i <= r)
	{
		if(arr[i] >= arr[p])
		{
			i++;
			continue;
		}
		int pivot = arr[p];
		arr[p] = arr[i];
		arr[i] = arr[p+1];
		arr[p+1] = pivot;
		p++;
		i++;
	}
	return p;
}

int kthSmallest(int arr[], int l, int r, int k)
{
	if(k > 0 && k <= r - l + 1)
	{
		int pos = partition(arr, l, r);
		if(pos - l == k - 1)
			return arr[pos];
		else if(pos - l > k - 1)
			return kthSmallest(arr, l, pos - 1, k);
		else
			return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}
	return INT_MAX;
}

void displayArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

