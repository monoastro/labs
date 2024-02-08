 //merge sort, bubble sort, binary searching, selection sort
#include "sorting.h"

void lab7()
{
	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Original array:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	// Bubble Sort
	bubbleSort(arr, n);
	printf("Sorted array using Bubble Sort:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	// Merge Sort
	int arr_merge[] = {12, 11, 13, 5, 6};
	mergeSort(arr_merge, 0, n - 1);
	printf("Sorted array using Merge Sort:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr_merge[i]);
	printf("\n");

	// Selection Sort
	int arr_selection[] = {12, 11, 13, 5, 6};
	selectionSort(arr_selection, n);
	printf("Sorted array using Selection Sort:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr_selection[i]);
	printf("\n");

	// Binary Search
	int x = 13;
	int result = binarySearch(arr_merge, 0, n - 1, x);
	if (result != -1)
		printf("Element %d is present at index %d\n", x, result);
	else
		printf("Element %d is not present in the array\n", x);
}
