#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in the array
*/

void shell_sort(int *array, size_t size)
{
	size_t i, n = 1, j;
	int temp;

	while (n < size / 3)
		n = n * 3 + 1;
	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= n && array[j - n] > temp; j -= n)
			{
				array[j] = array[j - n];
			}
			array[j] = temp;
		}
		n = (n - 1) / 3;
		print_array(array, size);
	}
}
