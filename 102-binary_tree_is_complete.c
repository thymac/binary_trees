#include <stdlib.h>
#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
size_t left_height = 1 + binary_tree_height(tree->left);
size_t right_height = 1 + binary_tree_height(tree->right);
if (left_height == right_height)
return (1);

return (0);
}
