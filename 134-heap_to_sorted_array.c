#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 * @heap: A pointer to the root node of the heap to convert
 * @size: An address to store the size of the array
 *
 * Return: A pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    size_t i, count = binary_tree_size(heap);

    if (heap == NULL || size == NULL)
        return (0);

    array = malloc(sizeof(int) * count);
    if (array == NULL)
        return (0);

    for (i = 0; i < count; i++)
        array[i] = heap_extract(&heap);

    *size = count;
    return (array);
}
