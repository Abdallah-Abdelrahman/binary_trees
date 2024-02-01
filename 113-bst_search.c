#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to node containing searched value, or NULL
 * if tree is NULL or value not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	return (tree->n > value ?
			bst_search(tree->left, value) : bst_search(tree->right, value));
}
