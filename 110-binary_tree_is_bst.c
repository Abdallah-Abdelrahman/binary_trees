#include "binary_trees.h"
int is_bst(const binary_tree_t *tree, int min, int max);
/**
 * binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 * Description:
 * - The left subtree of a node contains only nodes,
 *   with values less than the node’s value
 * - The right subtree of a node contains only nodes,
 *   with values greater than the node’s value
 * - The left and right subtree each must also be a binary search tree
 * - There must be no duplicate values
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}
/**
 * is_bst - helper function to check if a tree is valid BST
 * @tree: pointer to the root node of the tree to check
 * @min: min value starts from INT_MIN
 * @max: max value starts from INT_MAX
 *
 * Return: 1 if BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst(tree->left, min, tree->n - 1)
			&& is_bst(tree->right, tree->n + 1, max));
}
