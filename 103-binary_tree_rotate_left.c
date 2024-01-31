#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root, *pivot;

	if (!tree)
		return (tree);

	root = tree;
	pivot = root->right ? root->right : root->left;
	pivot->parent = root->parent;
	root->parent = pivot;
	root->right = pivot->left;
	pivot->left = root;

	return (pivot);
}
