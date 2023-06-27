#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
    int max_value = 0, i;
    int *count_array, *sorted_array;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* Create and initialize the count array */
    count_array = malloc((max_value + 1) * sizeof(int));
    if (count_array == NULL)
        return;

    for (i = 0; i <= max_value; i++)
        count_array[i] = 0;

    /* Count the occurrences of each value in the array */
    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Modify the count array to store the cumulative count */
    for (i = 1; i <= max_value; i++)
        count_array[i] += count_array[i - 1];

    /* Create the sorted array */
    sorted_array = malloc(size * sizeof(int));
    if (sorted_array == NULL)
    {
        free(count_array);
        return;
    }

    /* Place each element in its correct position in the sorted array */
    for (i = size - 1; i >= 0; i--)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    /* Copy the sorted array back to the original array */
    for (i = 0; i < size; i++)
        array[i] = sorted_array[i];

    /* Print the count array */
    printf("Counting array: ");
    for (i = 0; i <= max_value; i++)
        printf("%d ", count_array[i]);
    printf("\n");

    /* Free the allocated memory */
    free(count_array);
    free(sorted_array);
}
