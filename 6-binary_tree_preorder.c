#include "binary_trees.h"

/**
 * binary_tree_preorder - pre-order binary tree travelsal
 * @tree: pointer to the root node of the tree
 * @func: pointer to a func to call for each node.
 * The value in the node must be passed as a parameter to this function
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
