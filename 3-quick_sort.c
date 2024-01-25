#include "sort.h"

size_t partition_array(int array[], size_t lo, size_t hi, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	size_t pivot;

	if (size < 2 || array == NULL)
	{
		return;
	}

	if (size - 1 > 0)
	{
		pivot = partition_array(array, 0, size - 1, size);

		if (pivot > 0)
		{
			quick_sort(array, pivot);
		}

		if (pivot < size - 1)
		{
			quick_sort(array + pivot + 1, size - pivot - 1);
		}
	}
}


/**
 * partition_array - splits the array into two base on pivot
 * @array: array to be partitioned
 * @lo: the lowest index
 * @hi: the highest index
 * @size: size of the array
 *
 * Return: pivot index
 */

size_t partition_array(int array[], size_t lo, size_t hi, size_t size)
{
	int pivot = array[hi], temp = 0;
	size_t i = lo - 1;
	size_t j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[hi])
	{
		temp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
