#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to 1st element in array
 * @size: number of elements in array
 *
 * Return: pointer to the root of Binary Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i = 0;
	heap_t *root = NULL;

	if (!array || size == 0)
		return (root);

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
