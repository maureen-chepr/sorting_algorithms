#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merges two sets of data in ascending order
 * but they must already be sorted before hand
 * @array: original array of data
 * @buff: auxiliary array of data for merging
 * @min: min range of data in array
 * @mid: middle index for splitting the array
 * @max: max range of data in array
 */

void merge(int *array, int *buff, int min, int mid, int max)
{
	int i = min, j = mid + 1, k = min;

	while (i <= mid || j <= max)
	{
		if (i <= mid && (j > max || array[i] <= array[j]))
		{
			buff[k] = array[i];
			k++, i++;
		}
		else
		{
			buff[k] = array[j];
			k++, j++;
		}
	}

	for (i = min; i <= max; i++)
		array[i] = buff[i];
}

/**
 * merge_sort_recursive - recursive helper function for merge_sort
 * @array: array of data to be sorted
 * @buff: auxiliary array for merging
 * @min: min range of data in array
 * @max: max range of data in array
 */

void merge_sort_recursive(int *array, int *buff, int min, int max)
{
	if (min < max)
	{
		int mid = (min + max) / 2;

		merge_sort_recursive(array, buff, min, mid);
		merge_sort_recursive(array, buff, mid + 1, max);

		printf("Merging...\n");
		printf("[left]: ");
		printcheck(array, min, mid);

		printf("[right]: ");
		printcheck(array, mid + 1, max);

		merge(array, buff, min, mid, max);

		printf("[Done]: ");
		printcheck(array, min, max);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm (top-down approach)
 * @array: array of data to be sorted
 * @size: size of data
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (!array || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;

	merge_sort_recursive(array, buff, 0, size - 1);

	free(buff);
}

/**
 * printcheck - prints an array in a given range
 * @array: array of data to be print
 * @r1: start of range
 * @r2: end of range
 */
void printcheck(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
