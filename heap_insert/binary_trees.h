#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Binary Tree structure */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/* Function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree); /* Add this prototype */

#endif /* BINARY_TREES_H */

