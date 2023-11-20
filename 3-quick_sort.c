#include "sort.h"

/**
 * swap - swap two integers
 * @a: int
 * @b: int
 * Return: (void) Swaped int
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * l_part - Partition an array and using pivot
 * @array: Array
 * @low: int
 * @high: int
 * @size: size of array (size_t)
 * Return: index of pivote (int)
 */
int l_part(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}

/**
 * l_qsort - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void l_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = l_part(array, low, high, size);
		l_qsort(array, low, i - 1, size);
		l_qsort(array, i + 1, high, size);
	}
}

/**
 * quick_sort - Quick Sort Algorithme using lomuto partition
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */
void quick_sort(int *array, size_t size)
{
	l_qsort(array, 0, size - 1, size);
}
