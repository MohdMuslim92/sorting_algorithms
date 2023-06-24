#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *				using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, max = array[0];
	int *count, *sorted;
	ssize_t k;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (j = 0; j <= max; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);
	sorted = malloc(size * sizeof(int));
	if (sorted == NULL)
	{
		free(count);
		return;
	}
	for (k = size - 1; k >= 0; k--)
		sorted[--count[array[k]]] = array[k];
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(count);
	free(sorted);
}
