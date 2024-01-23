#include "sort.h"

/**
 * selection_sort - sorts an array of integer in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Returns: nothing
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, minVal;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		minVal = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minVal])
			{
				minVal = j;
			}
		}
		if (minVal != i)
		{
			temp = array[i];
			array[i] = array[minVal];
			array[minVal] = temp;
		}
		print_array(array, size);
	}
}
