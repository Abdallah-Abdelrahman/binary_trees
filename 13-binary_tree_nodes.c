#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: count of nodes with at least 1 child,
 * or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	left = binary_tree_nodes(tree->left) + 1;
	right = binary_tree_nodes(tree->right) + 1;

	return (left + right - 1);
}
