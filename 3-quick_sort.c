#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Recursive function for Quick sort
 *
 * @array: Pointer to the first element of the array
 * @low: Index of the low partition
 * @high: Index of the high partition
 * @size: Number of elements in the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
    int partition;

    if (low < high)
    {
        partition = lomuto_partition(array, low, high, size);
        quicksort_recursive(array, low, partition - 1, size);
        quicksort_recursive(array, partition + 1, high, size);
    }
}

/**
 * lomuto_partition - Performs the Lomuto partition scheme
 *
 * @array: Pointer to the first element of the array
 * @low: Index of the low partition
 * @high: Index of the high partition
 * @size: Number of elements in the array
 *
 * Return: The final partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot, i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
