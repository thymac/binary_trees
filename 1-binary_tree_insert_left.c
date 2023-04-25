#include <stdlib.h>
#include "binary_trees.h"

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value) {
  if (parent == NULL) {
    return NULL;
  }
  binary_tree_t *node = malloc(sizeof(binary_tree_t));
  if (node == NULL) {
    return NULL;
  }
  node->n = value;
  node->parent = parent;
  node->left = NULL;
  node->right = NULL;

  if (parent->left != NULL) {
    parent->left->parent = node;
    node->left = parent->left;
  }
  parent->left = node;

  return node;
}
