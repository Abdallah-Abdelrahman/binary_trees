#include "binary_trees.h"
void hack_betty(void);

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap,
 * 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
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

		if (tmp->left && tmp->left->n > tmp->n)
			return (0);
		if (tmp->right && tmp->right->n > tmp->n)
			return (0);

		/* dequeue */
		tmp = q.queue[q.front++];
	}

	free(q.queue);
	return (1);
}
