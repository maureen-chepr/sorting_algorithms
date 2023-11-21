#include "sort.h"

/**
 * heapify - Recursive function to heapify a subtree rooted with the given node
 * @array: Array to be sorted as a heap
 * @size: Size of the heap
 * @index: Index of the current node in the heap
 * @total_size: Total size of the array (for printing)
 */
void heapify(int *array, size_t size, size_t index, size_t total_size)
{
	size_t largest = index;
	size_t left = 2 * index + 1;
	size_t right = 2 * index + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		/* Swap the nodes and print the array */
		int temp = array[index];

		array[index] = array[largest];
		array[largest] = temp;
		print_array(array, total_size);

		/* Recursively heapify the affected sub-tree */
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - Function to sort an array using Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	/* Build max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* One by one extract elements */
	for (i = size - 1; i > 0; i--)
	{
		/* Move the current root to the end */
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);

		/* Call max heapify on the reduced heap */
		heapify(array, i, 0, size);
	}
}

