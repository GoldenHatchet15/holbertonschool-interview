#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
void print_array(int *array, size_t low, size_t high);
int recursive_binary(int *array, size_t low, size_t high, int value);

#endif /* SEARCH_ALGOS_H */
