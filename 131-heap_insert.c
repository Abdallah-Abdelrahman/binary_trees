#include "binary_trees.h"

/**
 * heapify_up - helper function to maintain the heap property
 * @node: double pointer to inserted node
 * @new: node after heapifying
 *
 * Return: Nothing
 */
void heapify_up(heap_t *node, heap_t **new)
{

	if (!node || !node->parent)
		return;

	if (node->n > node->parent->n)
	{
		/* swap */
		SWAP(node, node->parent);
		*new = node->parent;
	}

	heapify_up(node->parent, new);
}

/**
 * insert - helper function to inser int MAX HEAP
 * @root: pointer to the root node
 * @value:
 *
 * Return: newly node created
 */
heap_t *insert(heap_t *root, int value)
{
	heap_t *tmp = root, *node = NULL;
	queue_t q = QUEUE(q, QUEUE_SIZE);

	while (tmp)
	{
		if (!tmp->left)
		{
			node = tmp->left = binary_tree_node(tmp, value);
			heapify_up(tmp->left, &node);
			free(q.queue);
			return (node);
		}
		q.queue[q.rear++] = tmp->left;

		if (!tmp->right)
		{
			node = tmp->right = binary_tree_node(tmp, value);
			tmp->right = node;
			heapify_up(node, &node);
			free(q.queue);
			return (node);
		}
		q.queue[q.rear++] = tmp->right;
		tmp = q.queue[q.front++];
	}
	free(q.queue);
	return (NULL);
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	return (insert(*root, value));
}

