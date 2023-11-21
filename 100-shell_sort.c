#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * @array: array to sort
 * @size: array size
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, x, y;
	int tmp;

	if (!array || !size || size < 2)
		return;
	while (gap < (int)size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (x = gap; x < (int)size; x++)
		{
			tmp = array[x];
			y = x;
			while (y > (gap - 1) && array[y - gap] >= tmp)
			{
				array[y] = array[y - gap];
				y -= gap;
			}
			array[y] = tmp;
		}
		gap = gap / 3;
		print_array(array, size);
	}
}
