#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree.
 * Description:
 * - If the node to be deleted has two children,
 *   it must be replaced with its first in-order successor (not predecessor).
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree,
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	return (0);
}

bst_t *inorder_successor(binary_tree_t *node)
{
	bst_t *p;
	if (!node->right)
	{
		p = node->parent;
		while (p && node == p->right)
		{
			node = p;
			p = p->parent;
		}
		return (p);
	}

	return ();
}
