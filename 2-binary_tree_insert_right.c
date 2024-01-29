#include "binary_trees.h"

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
