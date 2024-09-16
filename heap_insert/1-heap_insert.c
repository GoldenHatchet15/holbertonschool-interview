#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * heapify_up - Maintains the max heap property by swapping nodes
 * @node: Pointer to the newly inserted node
 *
 * Return: Pointer to the inserted node after heapifying
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		/* Swap values with the parent */
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * insert_node - Helper function to insert a
 * node at the next available position
 * @root: Pointer to the root of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *insert_node(heap_t *root, int value)
{
	size_t size;
	size_t index;
	heap_t *new_node, *parent;
	int parent_dir;

	size = binary_tree_size(root);
	index = size + 1;  /* Position of the new node in a complete binary tree */
	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	parent = root;
	for (parent_dir = index / 2; parent_dir > 1; parent_dir /= 2)
	{
		if (parent_dir % 2 == 0)
			parent = parent->left;
		else
			parent = parent->right;
	}

	/* Insert as left or right child */
	if (index % 2 == 0)
		parent->left = new_node;
	else
		parent->right = new_node;
	new_node->parent = parent;

	return (new_node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!root)
		return (NULL);

	if (*root == NULL)  /* If the tree is empty, create the root node */
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new_node = insert_node(*root, value);
	if (!new_node)
		return (NULL);

	return (heapify_up(new_node));
    /* Heapify tree to maintain max-heap property */
}
