#include "binary_trees.h"

int is_bst(const binary_tree_t *tree, int min, int max);

int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst(tree, INT_MIN, INT_MAX));
}

int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	/* recursively check left and right */
	return (is_bst(tree->left, min, tree->n - 1) && is_bst(tree->right, tree->n + 1, max));
}
