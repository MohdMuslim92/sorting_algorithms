#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using
 * the Radix sort algorithm with the LSD approach.
 *
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	ssize_t j;
	int k, digits, max = array[0];
	int *count, *sorted;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (digits = 1; max / digits > 0; digits *= 10)
	{
		int num_buckets = 10;

		count = malloc(num_buckets * sizeof(int));
		if (count == NULL)
			return;
		sorted = malloc(size * sizeof(int));
		if (sorted == NULL)
		{
			free(count);
			return;
		}
		for (k = 0; k < num_buckets; k++)
			count[k] = 0;
		for (i = 0; i < size; i++)
			count[(array[i] / digits) % num_buckets]++;
		for (k = 1; k < num_buckets; k++)
			count[k] += count[k - 1];
		for (j = size - 1; j >= 0; j--)
		{
			sorted[count[(array[j] / digits) % num_buckets] - 1] = array[j];
			count[(array[j] / digits) % num_buckets]--;
		}
		for (i = 0; i < size; i++)
			array[i] = sorted[i];
		free(count);
		free(sorted);
		print_array(array, size);
	}
}

