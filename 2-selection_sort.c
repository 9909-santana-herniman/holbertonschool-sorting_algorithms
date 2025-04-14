#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in
 * ascending order using the selection sort algorithm.
 * @array: The array to sort.
 * @size: The number of elements in the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/* Assume the first element is the smallest */
		min_index = i;

		/* Look through the rest of the array for a smaller element */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		/* If smaller element found, swap it with current one */
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			/* Print array after each swap */
			print_array(array, size);
		}
	}

}
