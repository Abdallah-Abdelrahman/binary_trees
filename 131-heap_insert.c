#include "binary_trees.h"

void heapify(heap_t *node);
heap_t *insert_heap(heap_t *root, int value);
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

	return (insert_heap(*root, value));
}

/**
 * insert_heap - helper function to inser int MAX HEAP
 * @root: pointer to the root node
 * @value:
 *
 * Return: newly node created
 */
heap_t *insert_heap(heap_t *root, int value)
{
	heap_t *tmp = root;
	queue_t q = {0, 0, calloc(sizeof(heap_t), QUEUE_SIZE)};

	while (tmp)
	{
		if (!tmp->left)
		{
			tmp->left = binary_tree_node(tmp, value);
			heapify(tmp->left);
			return (tmp->left);
		}
		q.queue[q.rear++] = tmp->left;

		if (!tmp->right)
		{
			tmp->right = binary_tree_node(tmp, value);
			heapify(tmp->right);
			return (tmp->right);
		}
		q.queue[q.rear++] = tmp->right;
		tmp = q.queue[q.front++];
	}
	return (NULL);
}

/**
 * heapify - helper function to maintain the heap property
 * @node: double pointer to inserted node
 *
 * Return: Nothing
 */
void heapify(heap_t *node)
{

	if (!node || !node->parent)
		return;
	if (node->n > node->parent->n)
		/* swap */
		SWAP(node, node->parent);

	heapify(node->parent);
}
