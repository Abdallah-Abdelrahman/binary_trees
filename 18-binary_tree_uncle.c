#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: uncle, or NULL if node or parent is NULL
 * or it doesn't have one.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *gparent, *parent;

	if (!node || !node->parent)
		return (NULL);

	parent = node->parent;
	gparent = parent->parent;
	if (!gparent)
		return (NULL);

	return (gparent->left && gparent->left == parent ?
			gparent->right : gparent->left);
}
