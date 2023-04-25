#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *node = NULL;
if (tree == NULL)
return (NULL);
if (*tree == NULL)
{
*tree = binary_tree_node(*tree, value);
return (*tree);
}
if (value < (*tree)->n)
{
if ((*tree)->left == NULL)
{
node = binary_tree_node(*tree, value);
(*tree)->left = node;
return (node);
}
else
return (bst_insert(&((*tree)->left), value));
}
else if (value > (*tree)->n)
{
if ((*tree)->right == NULL)
{
node = binary_tree_node(*tree, value);
(*tree)->right = node;
return (node);
}
else
return (bst_insert(&((*tree)->right), value));
}
return (NULL);
}

