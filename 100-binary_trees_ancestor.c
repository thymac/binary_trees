#include<stdlib.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
if (!first || !second)
return NULL;
if (first == second)
return ((binary_tree_t *)first);
if (first == second->parent)
return ((binary_tree_t *)first);
if (second == first->parent)
return ((binary_tree_t *)second);
if (first->parent == second->parent)
return (first->parent);
if (first->parent)
{
if (first->parent->left == first)
{
if (second->parent->right == second)
return binary_trees_ancestor(first->parent, second->parent);
return binary_trees_ancestor(first->parent, second);
}
if (first->parent->right == first)
{
if (second->parent->left == second)
return binary_trees_ancestor(first->parent, second->parent);
return binary_trees_ancestor(first->parent, second);
}
}
if (second->parent)
{
if (second->parent->left == second)
{
if (first->parent->right == first)
return binary_trees_ancestor(second->parent, first->parent);
return binary_trees_ancestor(second->parent, first);
}
if (second->parent->right == second)
{
if (first->parent->left == first)
return binary_trees_ancestor(second->parent, first->parent);
return binary_trees_ancestor(second->parent, first);
}
}
return NULL;
}
