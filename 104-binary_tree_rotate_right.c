#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root, *pivot;

	if (!tree || (!tree->left))
		return (tree);

	root = tree;
	pivot = root->left;
	pivot->parent = root->parent;
	root->parent = pivot;
	root->left = pivot->right;
	if (root->left)
		root->left->parent = root;
	pivot->right = root;

	return (pivot);
}
