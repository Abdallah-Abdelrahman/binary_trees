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
				enqueue(&q, tmp->left);
			if (tmp->right)
				enqueue(&q, tmp->right);
			tmp = dequeue(&q);

			/* book keeping for the queue */
			i++;
		}
		free(q.queue);
	}
}

/**
 * enqueue - add element to the back of the queue
 * @q: struct of Queue_s (refer to binary_trees.h)
 * @tree: pointer to a node in binary tree
 *
 * Return: Nothing
 */
void enqueue(queue_t *q, binary_tree_t *tree)
{
	q->queue[q->rear++] = tree;
}

/**
 * dequeue - pop an element from the front of the queue
 * Description: we don't remove the element cuz removing
 * requires shifting which's O(n).
 * @q: struct of Queue_s (refer to binary_trees.h)
 *
 * Return: the poped element
 */
binary_tree_t *dequeue(queue_t *q)
{
	return (q->queue[q->front++]);
}
