#include "binary_trees.h"

/**
 * heapify_down - Fixes the heap property going down from a node.
 * @node: The starting node
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
 * get_last_node - Gets the last node (level order) in the heap.
 * @root: Pointer to the root
 * @size: Number of nodes in the heap
 * Return: Pointer to last node
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
    heap_t *path = root;
    size_t mask = 1UL << ((sizeof(size) * 8) - __builtin_clzl(size) - 1);

    while (mask >>= 1)
    {
        if (size & mask)
            path = path->right;
        else
            path = path->left;
    }

    return path;
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root
 * Return: size_t
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return 0;
    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to root of the heap
 * Return: value of extracted node, or 0 on failure
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
