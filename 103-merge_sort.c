#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm (top-down approach)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void merge_sort(int *array, size_t size)
{
	size_t i, mid = size / 2, left_size = mid, right_size = size - mid;
	int *left = array, *right = array + mid;
	int *merged = malloc(size * sizeof(int));

	if (array == NULL || size < 2)
		return;
	merge_sort(left, left_size);
	merge_sort(right, right_size);
	if (merged == NULL)
		return;
	merge(merged, left, left_size, right, right_size);
	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < left_size; i++)
	{
		printf("%d", left[i]);
		if (i < left_size - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (i = 0; i < right_size; i++)
	{
		printf("%d", right[i]);
		if (i < right_size - 1)
			printf(", ");
	}
	printf("\n");
	printf("[Done]: ");
	for (i = 0; i < size; i++)
	{
		array[i] = merged[i];
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
	free(merged);
}

/**
 * merge - Merges two sorted sub-arrays into a single sorted array
 * @array: The original array to store the merged result
 * @left: The left sub-array
 * @l_size: Number of elements in the left sub-array
 * @right: The right sub-array
 * @r_size: Number of elements in the right sub-array
 */

void merge(int *array, int *left, size_t l_size, int *right, size_t r_size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
		{
			array[k++] = left[i++];
		} else
		{
			array[k++] = right[j++];
		}
	}
	while (i < l_size)
		array[k++] = left[i++];
	while (j < r_size)
		array[k++] = right[j++];
}
