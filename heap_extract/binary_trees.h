#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/* Provided print function (only for testing, not checked during correction) */
void binary_tree_print(const binary_tree_t *);

/* Project-required function prototype */
int heap_extract(heap_t **root);

/* Helper function prototypes (may be used in your .c file) */
size_t binary_tree_size(const binary_tree_t *tree);
void heapify_down(heap_t *node);

#endif /* _BINARY_TREES_H_ */
