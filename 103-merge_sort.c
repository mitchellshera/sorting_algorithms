#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted array
 *
 * @array: Pointer to the original array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i, j, k;
    i = j = k = 0;

    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the top-down merge sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    size_t mid, i;
    int *left, *right;

    if (size < 2)
        return;

    mid = size / 2;
    left = array;
    right = array + mid;

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    merge(array, left, mid, right, size - mid);

    free(left);
}
