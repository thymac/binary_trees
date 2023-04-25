#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    /* Empty trees are max heaps */
    if (tree == NULL)
        return (1);

    /* Check if current node is less than its children */
    if (tree->left != NULL && tree->left->n > tree->n)
        return (0);
    if (tree->right != NULL && tree->right->n > tree->n)
        return (0);

    /* Recursively check if left and right subtrees are max heaps */
    if (!binary_tree_is_heap(tree->left) || !binary_tree_is_heap(tree->right))
        return (0);

    return (1);
}

