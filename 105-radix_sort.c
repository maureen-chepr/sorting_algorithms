#include "sort.h"
#include <stdint.h>

/**
 * get_max - Returns the maximum element from an array
 * @array: Array of integers
 * @size: Size of the array
 * Return: The maximum element
 */

int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * count_sort - Performs counting sort based on significant place
 * @array: Array of integers
 * @size: Size of the array
 * @exp: Exponent, representing the significant place
 */

void count_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: Array of integers
 * @size: Size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	size_t exp;

	if (size > 1)
	{
		max = get_max(array, size);

		for (exp = 1; max / exp > 0; exp *= 10)
		{
			count_sort(array, size, exp);
		}
	}
}
