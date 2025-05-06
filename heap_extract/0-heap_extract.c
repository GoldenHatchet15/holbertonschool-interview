#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_last_node - Gets the last node in level-order
 * @root: Pointer to the root node
 * @size: Size of the heap
 * Return: Pointer to last node
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t path;
	heap_t *node = root;

	if (!root || size == 0)
		return (NULL);

	/* Ignore the MSB (most significant bit) */
	for (path = 1UL << ((sizeof(size) * 8) - __builtin_clzl(size) - 2);
path > 0; path >>= 1)
	{
		if (size & path)
			node = node->right;
		else
			node = node->left;
	}

	return (node);
}

/**
 * heapify_down - Restores Max Heap property from top to bottom
 * @node: Pointer to the current node
 */
void heapify_down(heap_t *node)
{
	heap_t *largest;
	int temp;

	while (node)
	{
		largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			break;

		temp = node->n;
		node->n = largest->n;
		largest->n = temp;

		node = largest;
	}
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to the root node
 * Return: Value of the extracted node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last, *parent;
	size_t size;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = binary_tree_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root, size);
	(*root)->n = last->n;

	parent = last->parent;
	if (parent->right == last)
		parent->right = NULL;
	else
		parent->left = NULL;

	free(last);
	heapify_down(*root);

	return (value);
}
