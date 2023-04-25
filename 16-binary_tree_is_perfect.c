#include <stdlib.h>
#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height = 0, right_height = 0;
if (tree == NULL)
return (0);
if (tree->left != NULL)
left_height = 1 + binary_tree_height(tree->left);
if (tree->right != NULL)
right_height = 1 + binary_tree_height(tree->right);
if (left_height > right_height)
return (left_height);

return (right_height);
}

int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t left_height = 0, right_height = 0;
if (tree == NULL)
return (0);
left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);
if (left_height != right_height)
return (0);

return (1);
}
