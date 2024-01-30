#include "binary_trees.h"
void print_level(const binary_tree_t *tree, void (func)(int), size_t level);

/**
 * binary_tree_levelorder - goes through a binary tree.
 * Description: using level-order traversal (Breadth-first-search)
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i = 0;

	if (tree && func)
	{
		h = binary_tree_height(tree);
		for (i = 0; i <= h; i++)
			print_level(tree, func, i);
	}
}

/**
 * print_level - print all nodes in current level
 * @tree: pointer to root node
 * @func: pointer to a function to call for each node
 * @level: current level of the tree
 *
 * Return: Nothing
 *
 */
void print_level(const binary_tree_t *tree, void (func)(int), size_t level)
{
	if (level == 0)
	{
		func(tree->n);
		return;
	}

	print_level(tree->left, func, level - 1);
	print_level(tree->right, func, level - 1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right = binary_tree_height(tree->right) + 1;

	return ((right > left) ? right : left);
}
