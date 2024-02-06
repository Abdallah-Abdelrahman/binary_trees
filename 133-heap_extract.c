#include "binary_trees.h"
void repair_heap(heap_t *root);

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * Description: The root node must be freed
 * and replace with the last level-order node of the heap.
 * @root: double pointer to the root node of heap
 *
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int value;

	if (!root || !*root)
		return (0);
	value = (*root)->n;
	repair_heap(*root);

	return (value);
}

void repair_heap(heap_t *root)
{
	queue_t q = QUEUE(QUEUE_SIZE);
}
