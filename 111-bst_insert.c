#include "binary_trees.h"

binary_tree_t *_binary_tree_insert_right(bst_t *parent, int value);
binary_tree_t *_binary_tree_insert_left(bst_t *parent, int value);
bst_t *_bst_insert(bst_t *tree, int value);
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * Description:
 * - If the address stored in tree is NULL,
 *   the created node must become the root node.
 * - If the value is already present in the tree, it must be ignored.
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!*tree)
		/* root */
		return (*tree = (binary_tree_node(NULL, value)));

	return (_bst_insert(*tree, value));
}

/**
 * _bst_insert - helper function to insert
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *_bst_insert(bst_t *tree, int value)
{
	if (tree->n == value)
		return (NULL);
	if (tree->n < value && !tree->right)
		return (tree->right = binary_tree_node(tree, value));
	if (tree->n > value && !tree->left)
		return (tree->left = binary_tree_node(tree, value));
	return (tree->n > value ?
			_bst_insert(tree->left, value) : _bst_insert(tree->right, value));
}

