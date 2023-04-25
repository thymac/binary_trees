#include <stdlib.h>
#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree)
{
size_t left_height = 0, right_height = 0;
if (tree == NULL)
return (0);
if (tree->left != NULL)
left_height = 1 + binary_tree_is_full(tree->left);
if (tree->right != NULL)
right_height = 1 + binary_tree_is_full(tree->right);
if (left_height == right_height)
return (1);

return (0);
}
