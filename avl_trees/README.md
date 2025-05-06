# AVL Trees

This directory contains implementations and utilities for working with **AVL Trees**, a type of self-balancing binary search tree. The balance factor of each node in an AVL tree is maintained to ensure logarithmic time complexity for search, insertion, and deletion operations.

## Files

- **`0-binary_tree_is_avl.c`**  
    Function to check if a binary tree is a valid AVL tree.

- **`1-binary_tree_rotate_left.c`**  
    Function to perform a left rotation on a binary tree.

- **`2-binary_tree_rotate_right.c`**  
    Function to perform a right rotation on a binary tree.

- **`3-binary_tree_balance.c`**  
    Function to calculate the balance factor of a binary tree.

- **`4-binary_tree_insert.c`**  
    Function to insert a value into an AVL tree while maintaining balance.

- **`binary_tree_print.c`**  
    Utility function to print a binary tree in a structured format.

## Requirements

- Code is written in C.
- Follows the **Betty coding style**.
- Compiled using `gcc` with flags `-Wall -Werror -Wextra -pedantic`.

## Usage

To compile the files, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o avl_tree
```

Run the executable to test the AVL tree functionalities.

