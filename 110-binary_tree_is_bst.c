#include "binary_trees.h"

const binary_tree_t *max(const binary_tree_t *tree);
const binary_tree_t *min(const binary_tree_t *tree);

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (tree->left && max(tree->left)->n > tree->n)
		return (0);
	if (tree->right && min(tree->right)->n <= tree->n)
		return (0);
	return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));

}

const binary_tree_t *min(const binary_tree_t *tree)
{
	if (tree && tree->left)
		return min(tree->left);
	return (tree);
}
const binary_tree_t *max(const binary_tree_t *tree)
{
	if (tree && tree->right)
		return max(tree->right);
	return (tree);
}
