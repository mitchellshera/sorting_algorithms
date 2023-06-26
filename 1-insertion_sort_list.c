#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr = (*list)->next;

    while (curr != NULL)
    {
        listint_t *key = curr;
        listint_t *prev = key->prev;

        while (prev != NULL && prev->n > key->n)
        {
            prev->next = key->next;
            if (key->next != NULL)
                key->next->prev = prev;

            key->prev = prev->prev;
            key->next = prev;

            if (prev->prev != NULL)
                prev->prev->next = key;
            else
                *list = key;

            prev->prev = key;

            prev = key->prev;
        }

        curr = curr->next;
    }
}
