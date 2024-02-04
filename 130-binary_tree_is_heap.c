#include "binary_trees.h"
int is_heap(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap,
 * 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!binary_tree_is_complete(tree))
		return (0);

	return (is_heap(tree));
}

/**
 * is_heap - helper function to check recursively
 * @tree: pointer to root node
 *
 * Return: 1 if max heap, 0 otherwise
 */
int is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (tree->left && tree->n < tree->left->n)
		return (0);
	if (tree->right && tree->n < tree->right->n)
		return (0);
	return (is_heap(tree->left) && is_heap(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if it's complete, 0 if tree is NULL,
 * or it's not complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t q = {0, 0, NULL};
	const binary_tree_t *tmp;
	int is_not_full = 0;

	if (!tree)
		return (0);

	q.queue = calloc(sizeof(binary_tree_t), QUEUE_SIZE);
	tmp = tree;
	while (tmp)
	{
		if (tmp->left)
		{
			if (is_not_full)
			{
				free(q.queue);
				return (0);
			}
			/* enqueue */
			q.queue[q.rear++] = tmp->left;
		}
		else
			is_not_full = 1;
		if (tmp->right)
		{
			if (is_not_full)
			{
				free(q.queue);
				return (0);
			}
			q.queue[q.rear++] = tmp->right;
		}
		else
			is_not_full = 1;
		/* dequeue */
		tmp = q.queue[q.front++];
	}

	free(q.queue);
	return (1);
}
