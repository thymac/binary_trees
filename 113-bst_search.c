#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 * @tree: Pointer to the root node of the BST to search.
 * @value: The value to search in the tree.
 *
 * Return: Pointer to the node containing a value equals to value.
 *         NULL if tree is NULL or if nothing is found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (!tree)
        return (NULL);

    if (tree->n == value)
        return ((bst_t *)tree);

    if (value < tree->n)
        return (bst_search(tree->left, value));

    return (bst_search(tree->right, value));
}

