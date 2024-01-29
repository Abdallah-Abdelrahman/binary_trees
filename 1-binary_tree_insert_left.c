#include "binary_trees.h"

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
