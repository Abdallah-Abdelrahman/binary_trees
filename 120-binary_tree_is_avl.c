#include "binary_trees.h"
int is_avl(const binary_tree_t *tree);
size_t _binary_tree_height(const binary_tree_t *tree);
int _binary_tree_balance(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	if (!binary_tree_is_bst(tree))
		return (0);
	return (is_avl(tree));
}

/**
 * is_avl - helper function to check left and right subtrees
 * @tree: pointer to the root
 *
 * Return: 1 if it's avl, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
	int lfactor, rfactor;

	if (!tree)
		return (1);

	lfactor = _binary_tree_balance(tree->left);
	rfactor = _binary_tree_balance(tree->right);

	if (abs(lfactor - rfactor) <= 1)
		return (is_avl(tree->left) && is_avl(tree->right));

	return (0);
}
/**
 * _binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor, or 0 if tree is NULL
 */
int _binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left = _binary_tree_height(tree->left) + 1;
	if (tree->right)
		right = _binary_tree_height(tree->right) + 1;

	return (left - right);
}

/**
 * _binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, 0 if NULL
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left = _binary_tree_height(tree->left) + 1;
	if (tree->right)
		right = _binary_tree_height(tree->right) + 1;

	return (MAX(left, right));
}
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
