#include <stdlib.h>
#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree)
{
size_t size = 1;
if (tree == NULL)
return (0);
size += binary_tree_size(tree->left);
size += binary_tree_size(tree->right);
return (size);
}
