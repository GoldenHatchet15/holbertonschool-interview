#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* Include string.h for memset and strlen */

/* Utility function prototypes */
static size_t _height(const binary_tree_t *tree);
static size_t _print_t(const binary_tree_t *tree, int is_left, int offset, int depth, char **s);

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    size_t height, i, j;

    if (!tree)
        return;

    height = _height(tree);
    s = malloc(sizeof(*s) * (height * 2));
    if (!s)
        return;

    for (i = 0; i < height * 2; i++)
    {
        s[i] = malloc(255);
        if (!s[i])
            return;
        memset(s[i], 32, 255); /* Fill the string with spaces */
    }

    _print_t(tree, 0, 0, 0, s);

    for (i = 0; i < height * 2; i++)
    {
        for (j = 254; j > 1 && s[i][j] == ' '; j--)
            ;
        s[i][j + 1] = '\0';
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}

/**
 * _height - Measures the height of a binary tree
 * @tree: Pointer to the node to measure the height
 *
 * Return: The height of the tree
 */
static size_t _height(const binary_tree_t *tree)
{
    size_t left, right;

    if (!tree)
        return (0);
    left = tree->left ? 1 + _height(tree->left) : 0;
    right = tree->right ? 1 + _height(tree->right) : 0;
    return (left > right ? left : right);
}

/**
 * _print_t - Stores recursively each level of the binary tree into a string
 * @tree: Pointer to the node to print
 * @is_left: Flag indicating whether the node is a left child
 * @offset: Offset where the root is printed
 * @depth: Depth of the node
 * @s: Buffer to store the print
 *
 * Return: Number of characters printed
 */
static size_t _print_t(const binary_tree_t *tree, int is_left, int offset, int depth, char **s)
{
    if (!tree)
        return (0);

    char b[6];
    size_t width, left, right;

    /* Add debug print */
    printf("Processing node with value: %d, depth: %d, offset: %d\n", tree->n, depth, offset);

    sprintf(b, "(%03d)", tree->n);
    width = strlen(b);

    left = _print_t(tree->left, 1, offset, depth + 1, s);
    right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

    for (size_t i = 0; i < width; i++)
        s[depth * 2][offset + left + i] = b[i];

    if (depth && is_left)
    {
        for (size_t i = 0; i < width + right; i++)
            s[(depth * 2) - 1][offset + left + width / 2 + i] = '-';
        s[(depth * 2) - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (size_t i = 0; i < left + width; i++)
            s[(depth * 2) - 1][offset - width / 2 + i] = '-';
        s[(depth * 2) - 1][offset + left + width / 2] = '.';
    }

    return (left + width + right);
}
