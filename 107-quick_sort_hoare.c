#include "sort.h"
/**
 * _swap - swaps the positions of two elements
 * @array: array
 * @item1: array element
 * @item2: array element
 * Return: void
 */

void _swap(int *array, ssize_t item1, ssize_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 * hoare_partition - partitions the array
 * @array: array
 * @f_el: first array element
 * @l_el: last array element
 * @size: array size
 * Return: position of last element sorted
 */

int hoare_partition(int *array, int f_el, int l_el, int size)
{
	int curr = f_el - 1, find = l_el + 1;
	int pivot = array[l_el];

	while (1)
	{

		do {
			curr++;
		} while (array[curr] < pivot);
		do {
			find--;
		} while (array[find] > pivot);
		if (curr >= find)
			return (curr);
		_swap(array, curr, find);
		print_array(array, size);
	}
}
/**
 * q_h_sort - function that performs quicksort
 * @array: array
 * @f_el: first array element
 * @l_el: last array element
 * @size: array size
 * Return: void
 */

void q_h_sort(int *array, ssize_t f_el, ssize_t l_el, int size)
{
	ssize_t pos = 0;

	if (f_el < l_el)
	{
		pos = hoare_partition(array, f_el, l_el, size);
		q_h_sort(array, f_el, pos - 1, size);
		q_h_sort(array, pos, l_el, size);
	}
}

/**
 * quick_sort_hoare - prepare the terrain to quicksort algorithm
 * @array: array
 * @size: array size
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_h_sort(array, 0, size - 1, size);
}

