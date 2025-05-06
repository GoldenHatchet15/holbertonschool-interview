#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h> 


/**
 * height - Calculates the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height of the tree
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Checks if a tree is a valid Binary Search Tree
 * @tree: Pointer to the root node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * Return: 1 if valid BST, otherwise 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - Checks if a binary tree is AVL
 * @tree: Pointer to the root node
 * Return: 1 if AVL, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (1);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node
 * Return: 1 if valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	return (is_avl(tree));
}
