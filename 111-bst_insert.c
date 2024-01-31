#include "binary_trees.h"

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
		return (binary_tree_insert_right(tree, value));
	if (tree->n > value && !tree->left)
		return (binary_tree_insert_left(tree, value));
	return (tree->n > value ?
			_bst_insert(tree->left, value) : _bst_insert(tree->right, value));
}

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * Description: If parent already has a right-child,
 * the new node must take its place,
 * and the old right-child must be set as the right-child of the new node.
 * @parent: ointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);
	if (!parent->right)
	{
		parent->right = new_node;
		return (new_node);
	}
	new_node->right = parent->right;
	parent->right->parent = new_node;
	parent->right = new_node;

	return (new_node);
}

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * Description: If parent already has a left-child,
 * the new node must take its place, and the old left-child
 * must be set as the left-child of the new node.
 * @parent: is a pointer to the node to insert the left-child in
 * @value:  value to store in the new node
 *
 * Return:  pointer to the created node,
 * or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);
	if (!parent->left)
	{
		parent->left = new_node;
		return (new_node);
	}
	new_node->left = parent->left;
	parent->left->parent = new_node;
	parent->left = new_node;

	return (new_node);
}
