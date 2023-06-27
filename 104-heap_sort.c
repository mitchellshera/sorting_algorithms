#include "sort.h"

/**
 * sift_down - Helper function to perform the sift-down operation in heap sort
 * @array: The integer array to sort
 * @start: The start index of the heap
 * @end: The end index of the heap
 * @size: The size of the array
 *
 * Description: This function sifts the element at the start index down the heap
 * to its proper position within the heap.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	while (2 * root + 1 <= end)
	{
		size_t child = 2 * root + 1;
		size_t swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;

		int temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);

		root = swap;
	}
}

/**
 * heap_sort - Sorts the array using the heap sort algorithm
 * @array: The integer array to sort
 * @size: The size of the array
 *
 * Description: This function applies the sift-down heap sort algorithm to
 * sort the elements of the array in ascending order.
 */
void heap_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	/* Build the max heap */
	for (int i = size / 2 - 1; i >= 0; i--)
		sift_down(array, i, size - 1, size);

	/* Heap sort */
	for (int i = size - 1; i > 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);

		sift_down(array, 0, i - 1, size);
	}
}
