#include "sort.h"

/**
 * sift_down - Perform sift-down operation on the heap
 * @array: Pointer to the array
 * @size_init: Original size of the array
 * @size: Size of the current heap
 * @root: Index of the root of the tree
 */
void sift_down(int *array, size_t size_init, size_t size, size_t root)
{
	size_t left, right, largest;
	int temp;

	left = 2 * root + 1;
	right = left + 1;
	largest = root;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, size_init);
		sift_down(array, size_init, size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (!array || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, size, i - 1);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, i, 0);
	}
}
