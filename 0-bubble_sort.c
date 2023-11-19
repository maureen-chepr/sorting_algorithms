#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array to sort
 * @size: array size
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int n;

	if (size < 2)
		return;
	for (x = 0; x < size; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				n = array[y];
				array[y] = array[y + 1];
				array[y + 1] = n;
				print_array(array, size);
			}
		}
	}
}
