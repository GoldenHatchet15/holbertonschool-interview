#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *prev, *curr;

    if (!list)
        return (NULL);

    curr = list;
    while (curr->express && curr->express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr->express->index, curr->express->n);
        curr = curr->express;
    }

    prev = curr;
    if (curr->express)
    {
        curr = curr->express;
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
    }
    else
    {
        while (curr->next)
            curr = curr->next;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, curr->index);

    while (prev && prev->index <= curr->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }

    return (NULL);
}
