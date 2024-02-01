#include "binary_trees.h"

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
