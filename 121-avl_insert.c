#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * Description:
 * - If the address stored in tree is NULL,
 *   the created node must become the root node.
 * - The resulting tree after insertion, must be a balanced AVL Tree.
 * @tree: double pointer to the root node of the AVL tree for inserting value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to created node or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!*tree)
		/* root */
		return (*tree = binary_tree_node(NULL, value));
	return (0);
}
