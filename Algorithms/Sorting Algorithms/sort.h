#ifndef SORT_H
#define SORT_H

void insertSort(int arr[], int size);
void mergeSort(int arr[], int size);
void quickSort(int arr[], int size);
void quickSortHelper(int arr[], int l, int r);
int partition(int arr[], int l, int r);
int kthSmallest(int arr[], int l, int r, int k);
void displayArray(int arr[], int size);

#endif