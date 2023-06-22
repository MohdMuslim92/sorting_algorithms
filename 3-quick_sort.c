#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *				the QuickSort algorithm with Lomuto partition scheme.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursion(array, 0, size - 1, size);
}

/**
 * quicksort_recursion - Recursive helper function for QuickSort.
 *
 * @array: The array to be sorted
 * @low: Starting index of the subarray to be sorted
 * @high: Ending index of the subarray to be sorted
 * @size: The size of the array
*/
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_idx = partition(array, low, high);

		print_array(array, size);
		quicksort_recursion(array, low, partition_idx - 1, size);
		quicksort_recursion(array, partition_idx + 1, high, size);
	}
}

/**
 * partition - Lomuto partition scheme for QuickSort.
 *
 * @array: The array to be partitioned
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 *
 * Return: Index of the pivot element after partitioning
*/

int partition(int *array, int low, int high)
{
	int i = low - 1;
	int j, temp;
	int pivot = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
	}

	return (i + 1);
}
