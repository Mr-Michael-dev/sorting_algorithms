#include "sort.h"

/**
 * quick-sort - sorts an array of integers in ascending order
 * @arrray: array to be sorted
 * @size: size of the array
 *
 * Returns: nothing
 */

void quick_sort(int *array, size_t size)
{
	size_t pivot = size - 1;
	size_t i, j, temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i; j < size - i - 1; j++)
		{
			if (array[pivot] < array[pivot - 1])
			{
				temp = array[pivot];
				array[pivot] = array[pivot - 1];
				array[pivot - 1] = temp;
				print_array(array, size);
			}
			quick_sort(array, size - 1);
		}
	}
}
