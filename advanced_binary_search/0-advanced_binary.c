#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @low: Starting index
 * @high: Ending index
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		if (i > low)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * recursive_binary - Recursively searches for a value in a sorted array
 * @array: Pointer to first element of the array
 * @low: Starting index
 * @high: Ending index
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int recursive_binary(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);
	mid = low + (high - low) / 2;

	if (array[mid] == value && (mid == low || array[mid - 1] != value))
		return (mid);
	else if (array[mid] >= value)
		return (recursive_binary(array, low, mid, value));
	else
		return (recursive_binary(array, mid + 1, high, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursive_binary(array, 0, size - 1, value));
}
