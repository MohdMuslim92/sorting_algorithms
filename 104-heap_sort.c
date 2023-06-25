#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *				the Heap sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */

void heap_sort(int *array, size_t size)
{
	ssize_t i;
	int temp;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] =  array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - Adjusts the heap rooted at the given root index to
 *				maintain the max heap property.
 *
 * @array: The array representing the heap.
 * @size: The total number of elements in the heap.
 * @root: The index of the root of the heap to be heapified.
 * @arr_size: The size of the original array
 */

void heapify(int *array, size_t size, size_t root, size_t arr_size)
{
	size_t large = root, left = 2 * root + 1, right = 2 * root + 2;
	int temp;

	if (left < size && array[left] > array[large])
		large = left;
	if (right < size && array[right] > array[large])
		large = right;
	if (large != root)
	{
		temp = array[root];
		array[root] = array[large];
		array[large] = temp;
		print_array(array, arr_size);
		/*printf("\nsize :%ld\n", arr_size);*/
		heapify(array, size, large, arr_size);
	}
}
