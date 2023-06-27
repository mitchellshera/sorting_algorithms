#include "sort.h"

/**
 * merge_arrays - Merges two subarrays into a single sorted array
 * @array: The integer array to sort
 * @start: The start index of the first subarray
 * @mid: The mid index separating the two subarrays
 * @stop: The stop index of the second subarray
 * @temp: The temporary array to hold the merged elements
 *
 * Description: This function compares and merges two subarrays of the original array
 * into a single sorted array. It uses the temp array to store the merged elements.
 */
void merge_arrays(int *array, size_t start, size_t mid, size_t stop, int *temp)
{
	size_t i = start, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);

	for (k = start; k < stop; k++)
	{
		if (i < mid && (j >= stop || array[i] <= array[j]))
		{
			temp[k] = array[i++];
		}
		else
		{
			temp[k] = array[j++];
		}
	}

	printf("[Done]: ");
	print_array(temp + start, stop - start);
}

/**
 * merge_sort_recursive - Recursively sorts the array using merge sort
 * @array: The integer array to sort
 * @start: The start index of the current subarray
 * @stop: The stop index of the current subarray
 * @temp: The temporary array used for merging
 *
 * Description: This function applies merge sort recursively to the subarrays
 * of the original array. It divides the array into smaller subarrays until the
 * size is less than 2, and then merges them back together in sorted order.
 */
void merge_sort_recursive(int *array, size_t start, size_t stop, int *temp)
{
	size_t mid;

	mid = (start + stop) / 2;

	if (stop - start < 2)
	{
		return;
	}

	merge_sort_recursive(temp, start, mid, array);
	merge_sort_recursive(temp, mid, stop, array);
	merge_arrays(temp, start, mid, stop, array);
}

/**
 * merge_sort - Sorts the array using the merge sort algorithm
 * @array: The integer array to sort
 * @size: The size of the array
 *
 * Description: This function initializes the merge sort algorithm by creating a
 * temporary array, copying the elements from the original array, and calling the
 * recursive merge_sort_recursive function to perform the sorting. It then frees
 * the memory allocated for the temporary array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;
	size_t i;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	for (i = 0; i < size; i++)
		temp[i] = array[i];

	merge_sort_recursive(array, 0, size, temp);

	free(temp);
}
