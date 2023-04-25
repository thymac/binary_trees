#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * rebuild_heap - Rebuilds a binary heap from a given node
 * @node: Pointer to the root node of the binary heap
 */
void rebuild_heap(binary_tree_t *node)
{
    if (node == NULL)
	return;
    binary_tree_t *largest = node;
    binary_tree_t *l = node->left;
    binary_tree_t *r = node->right;

    if (l && l->n > largest->n)
        largest = l;

    if (r && r->n > largest->n)
        largest = r;

    if (largest != node)
    {
        swap(&(node->n), &(largest->n));
        rebuild_heap(largest);
    }
}

/**
 * get_heap_array - Creates an array of all values in a binary heap
 * @root: Pointer to the root node of the binary heap
 * Return: Pointer to the newly created array, or NULL on failure
 */
int *get_heap_array(const binary_tree_t *root)
{
    int *array;
    size_t size, i;

    if (root == NULL)
        return 0;

    size = binary_tree_size(root);
    array = malloc(size * sizeof(int));
    if (array == NULL)
        return 0;

    for (i = 0; i < size; i++)
        array[i] = heap_extract((heap_t **)&root);

    for (i = 0; i < size; i++)
        heap_insert((heap_t **)&root, array[i]);

    return array;
}

/**
 * heap_extract - Extracts the root value of a binary heap
 * @root: Pointer to the root node of the binary heap
 * Return: The value of the root node, or 0 if root is NULL or the heap is empty
 */
int heap_extract(binary_tree_t **root)
{
    if (root == NULL || *root == NULL)
        return 0;

    int value = (*root)->n;

    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        free(*root);
        *root = NULL;
        return value;
    }

    int *arr = get_heap_array(*root);
    size_t n = binary_tree_size(*root);
    swap(&arr[0], &arr[n - 1]);

    n--;
    rebuild_heap(*root);

    *root = array_to_heap(arr, n);

    free(arr);

    return value;
}
