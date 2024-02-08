 //merge sort, bubble sort, binary searching, selection sort
#include "sorting.h"

void lab7()
{
	int choice, size, *arr, data, result;
	while(1)
	{
		printf("\nenter option:\n (0) merge sort\n (1) binary search\n (2) bubble sort \n (3) selection sort\n ");
		scanf("%d", &choice);

		printf("Enter size of array to sort/search\n");
		scanf("%d", &size);
		arr = (int*)malloc(sizeof(int)*size);
		printf("Enter array in unsorted form\n");
		for(int i = 0; i<size; i++) scanf("%d", &arr[i]);

		switch(choice)
		{
			case 0:
				mergeSort(arr, 0, size - 1);
				printf("Sorted array using Merge Sort:\n");
				for (int i = 0; i < size; i++) printf("%d ", arr[i]);
				printf("\n");
				break;
			case 1:
				mergeSort(arr, 0, size - 1);
				printf("Sorted array using Merge Sort:\n");
				for (int i = 0; i < size; i++) printf("%d ", arr[i]);
				printf("\n");

				printf("Enter data to search: ");
				scanf("%d", &data);
				result = binarySearch(arr, 0, size - 1, data);
				if (result != -1) printf("Element %d is present at index %d\n", data, result);
				else printf("Element %d is not present in the array\n", data);
				break;
			case 2:
				bubbleSort(arr, size);
				printf("Sorted array using Bubble Sort:\n");
				for (int i = 0; i < size; i++) printf("%d ", arr[i]);
				printf("\n");
				break;
			case 3:
				selectionSort(arr, size);
				printf("Sorted array using Selection Sort:\n");
				for (int i = 0; i < size; i++) printf("%d ", arr[i]);
				printf("\n");
				break;
		}
		free(arr);
	}
}
