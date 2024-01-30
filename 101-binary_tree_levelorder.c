#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree.
 * Description: using level-order traversal (Breadth-first-search),
 * time coplexity is O(n).
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i = 0, size = QUEUE_SIZE;
	queue_t q = {0, 0, NULL};
	const binary_tree_t *tmp;

	if (tree && func)
	{
		q.queue = calloc(sizeof(binary_tree_t), size);
		tmp = tree;
		while (tmp)
		{
			if (i == size - 1)
			{
				size *= 2;
				q.queue = realloc(q.queue, size * sizeof(binary_tree_t));
			}

			func(tmp->n);
			if (tmp->left)
				q.queue[q.rear++] = tmp->left;
			if (tmp->right)
				q.queue[q.rear++] = tmp->right;

			tmp = q.queue[q.front++];

			/* book keeping for the queue */
			i++;
		}
		free(q.queue);
	}
}
