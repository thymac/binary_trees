#include <stdlib.h>
#include "binary_trees.h"

int binary_tree_is_leaf(const binary_tree_t *node) {
  binary_tree_is_leaf(node->left);
  binary_tree_is_leaf(node->right);

  if (node->left == NULL && node->right == NULL) {
    return 1;
  } 
  return 0;
}
