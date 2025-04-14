#include "sort.h"

/**
 * swap_ints - Swaps two integers
 * @a: First integer.
 * @b: Second integer.
 */
void swap_ints(int *a, int *b, int *array, size_t size)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Partitions the array using Lomuto scheme.
 * @array: The array to sort.
 * @low: Starting index.
 * @high: Ending index.
 * @size: Total size of the array (for printing).
 * Return: Index of the pivot after partition.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j], array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap_ints(&array[i], &array[high], array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - Recursive quick sort function
 * @array: Array to sort.
 * @low: Starting index.
 * @high: Ending index.
 * @size: Size of the full array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
