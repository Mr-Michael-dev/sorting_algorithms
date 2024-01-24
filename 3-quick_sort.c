#include "sort.h"

size_t partition_array(int array[], size_t lo, size_t hi);

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

	if (size <= 1 || array == NULL)
	{
		return;
	}

	pivot = partition_array(array, 0, size - 1);

	if (pivot > 0)
	{
		quick_sort(array, pivot);
	}

	if (pivot < size - 1)
	{
		quick_sort(array + pivot + 1, size - pivot - 1);
	}
}


/**
 * partition_array - splits the array into two base on pivot
 * @array: array to be partitioned
 * @lo: the lowest index
 * @hi: the highest index
 *
 * Return: pivot index
 */

size_t partition_array(int array[], size_t lo, size_t hi)
{
	int pivot = array[hi], temp;
	size_t i = lo - 1;
	size_t j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;

			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, hi + 1);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[hi];
	array[hi] = temp;

	return (i + 1);
}
