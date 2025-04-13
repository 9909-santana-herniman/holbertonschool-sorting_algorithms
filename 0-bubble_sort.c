#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 * @a: Pointer to the first int.
 * @b: Pointer to the second int.
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * bubble_sort - Sorts an array of integers in acending order using
 * the bubble sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	/* If the array is NULL or has less than 2 elements, its sorted */
	if (array == NULL || size < 2)
		return;

	/* Outer loop to pass through array */
	for (i = 0; i < size - 1; i++)
	{
		/* Inner loop to compare adjacent elements and swap */
		for (j = 0; j < size - i - 1; j++)
		{
			/* If current element is greater, swap */
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
}
