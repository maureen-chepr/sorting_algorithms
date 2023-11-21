#include <stdlib.h>
#include "sort.h"

/**
 * countSort - Counting sort algorithm for Radix sort
 *
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Exponent for the current significant digit
 * @buff: Buffer for temporary storage
 */
void countSort(int *array, size_t size, int exp, int *buff);

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 *
 * @array: Array of data to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max = array[0];
	int exp = 1;
	int *buff;

	if (size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, buff);
		print_array(array, size);
	}

	free(buff);
}

/**
 * countSort - Counting sort algorithm for Radix sort
 *
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Exponent for the current significant digit
 * @buff: Buffer for temporary storage
 */
void countSort(int *array, size_t size, int exp, int *buff)
{
	int carr[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		carr[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		carr[i] += carr[i - 1];

	for (i = size - 1; i < size; i--)
	{
		buff[carr[(array[i] / exp) % 10] - 1] = array[i];
		carr[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

