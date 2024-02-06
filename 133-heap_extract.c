#include "binary_trees.h"
void heapify_down(heap_t *tree);
void extract_root(heap_t *root);

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
	int value = 0;

	if (!root || !*root)
		return (value);

	value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
	}
	else
		extract_root(*root);

	return (value);
}

/**
 * extract_root - helper function to extract the root
 * @root: pointer to root of max heap binary tree
 *
 * Return: Nothing
 */
void extract_root(heap_t *root)
{
	queue_t q = QUEUE(q, QUEUE_SIZE);

	q.queue[q.rear++] = root;

	while (q.front != q.rear)
	{
		/* dequeue */
		root = q.queue[q.front++];

		if (root->left)
			/* enqueue left child */
			q.queue[q.rear++] = root->left;
		if (root->right)
			/* enqueue right child */
			q.queue[q.rear++] = root->right;
	}

	q.queue[0]->n = q.queue[q.rear - 1]->n;
	if (q.queue[q.rear - 1]->parent->left == q.queue[q.rear - 1])
		q.queue[q.rear - 1]->parent->left = NULL;
	else
		q.queue[q.rear - 1]->parent->right = NULL;
	free(q.queue[q.rear - 1]);
	heapify_down(q.queue[0]);

	free(q.queue);
}
/**
 * heapify_down - restore the max heap property
 * @tree: heap binary tree to restore its max heap property
 *
 * Return: Nothing
 */
void heapify_down(heap_t *tree)
{
	heap_t *child;

	if (!tree)
		return;
	child = tree->left ? tree->left : tree->right;
	if (!child)
		return;
	if (tree->left && tree->right)
	{
		if (tree->left->n > tree->right->n)
		{
			if (tree->left->n > tree->n)
			{
				SWAP(tree->left, tree);
				heapify_down(tree->left);
			}
		}
		else if (tree->right->n > tree->n)
		{
			SWAP(tree->right, tree);
			heapify_down(tree->right);
		}
	}
	else if (child->n > tree->n)
	{
		SWAP(tree, child);
		heapify_down(child == tree->left ? tree->left : tree->right);
	}
}

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the node
 *
 * Return: pointer to the new node,
 * or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}
