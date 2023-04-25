#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify_up - Recursive function to maintain max-heap property after inserting
 * a new node.
 * @node: Pointer to the node to compare and swap with its parent.
 * Return: Pointer to the new node.
 */
heap_t *heapify_up(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }

    return node;
}

/**
 * get_parent_node - Finds the parent node of the new node to be inserted.
 * @root: Pointer to the root node of the tree to search for the parent.
 * Return: Pointer to the parent node.
 */
heap_t *get_parent_node(heap_t *root)
{
    heap_t *parent = NULL;
    size_t left_size, right_size;

    left_size = binary_tree_size(root->left);
    right_size = binary_tree_size(root->right);

    if (!root)
        return (NULL);
    if (!left_size || !right_size)
        return (root);

    if (left_size <= right_size)
        parent = get_parent_node(root->left);
    else if (left_size > right_size)
        parent = get_parent_node(root->right);

    return (parent);
}

/**
 * heap_insert - Inserts a value into a max binary heap.
 * @root: Double pointer to the root node of the heap.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!(*root))
    {
        *root = new_node;
        return (new_node);
    }

    parent = get_parent_node(*root);
    new_node->parent = parent;

    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    heapify_up(new_node);

    return (new_node);
}

