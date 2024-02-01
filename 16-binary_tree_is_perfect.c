#include "binary_trees.h"
size_t _binary_tree_height(const binary_tree_t *tree);
size_t _binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect or 0 if not or tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h;

	if (!tree)
		return (0);

	h = _binary_tree_height(tree);
	if (_pow(2, h + 1) - 1 == _binary_tree_size(tree))
		return (1);

	return (0);
}

/**
 * _binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of tree, or 0 if tree is NULL
 */
size_t _binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + _binary_tree_size(tree->left) + _binary_tree_size(tree->right));
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

	return ((right > left) ? right : left);
}

/**
 * _pow - calculates the power
 * @base: base
 * @exp: exponent
 *
 * Return: the power
 */
size_t _pow(int base, int exp)
{
	if (exp == 0)
		return (1);
	return (base * _pow(base, exp - 1));
}
