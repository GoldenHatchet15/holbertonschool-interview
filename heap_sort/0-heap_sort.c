#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: First integer.
 * @b: Second integer.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Maintains the max heap property for a subtree.
 * @array: The array to be sorted.
 * @size: Size of the array.
 * @n: Size of heap.
 * @i: Index of the root.
 */
void heapify(int *array, size_t size, size_t n, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        print_array(array, size);
        heapify(array, size, n, largest);
    }
}

/**
 * heap_sort - Sorts an array using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, size, i, 0);
    }
}
