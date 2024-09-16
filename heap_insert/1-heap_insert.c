#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree (number of nodes)
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * find_parent - Finds the parent node
 * for the next insertion in a complete binary tree
 * @root: Pointer to the root node of the binary tree
 * @size: Size of the tree
 *
 * Return: Pointer to the parent node
 */
binary_tree_t *find_parent(binary_tree_t *root, size_t size)
{
	size_t bit;
	binary_tree_t *parent = root;

	/* Skip the most significant bit (root node is already assigned) */
	for (bit = 1 << (sizeof(size_t) * 8 - 1); bit > 1; bit >>= 1)
	{
		if (size & bit)
		{
			if (bit > 2)
				parent = parent->right;
			else
				return (parent);
		}
		else
		{
			if (bit > 2)
				parent = parent->left;
			else
				return (parent);
		}
	}
	return (NULL);
}

/**
 * heapify_up - Maintains the Max-Heap property by bubbling up
 * @node: Pointer to the newly inserted node
 * Return: Pointer to the node after heapifying
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
 * insert_at_last_position - Helper function to insert at the correct position
 * @root: Pointer to the root node of the binary tree
 * @value: Value to insert into the new node
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *insert_at_last_position(heap_t *root, int value)
{
	binary_tree_t *new_node, *parent;
	size_t size = binary_tree_size(root) + 1;
    /* Total nodes after inserting the new node */

	parent = find_parent(root, size);
	if (!parent)
		return (NULL);

	/* Insert as left or right child */
	if (!parent->left)
		parent->left = binary_tree_node(parent, value);
	else
		parent->right = binary_tree_node(parent, value);

	new_node = (!parent->left ? parent->left : parent->right);
	return (heapify_up(new_node));
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (!*root) /* If the heap is empty, create the root node */
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	return (insert_at_last_position(*root, value));
}
