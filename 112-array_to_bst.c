#include <stdlib.h>
#include "binary_trees.h"
/**
 * bst_free - Frees a binary search tree
 *
 * @tree: Pointer to the root node of the tree to free
 *
 * Description: This function frees a binary search tree. The function
 * recursively traverses the tree in post-order, freeing each node until
 * the entire tree has been freed.
 */
void bst_free(bst_t *tree)
{
    if (tree == NULL) {
        return;
    }
    
    bst_free(tree->left);
    bst_free(tree->right);
    free(tree);
}
/**
 * array_to_bst - Builds a Binary Search Tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
bst_t *root = NULL;
bst_t *node;
size_t i;
if (array == NULL || size == 0)
return (NULL);
for (i = 0; i < size; i++)
{
node = bst_insert(&root, array[i]);
if (node == NULL)
{
bst_free(root);
return (NULL);
}
}
return (root);
}
