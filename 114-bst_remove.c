#include "binary_trees.h"

bst_t *_bst_search(const bst_t *tree, int value);
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
	bst_t *successor = NULL, *node;

	if (!root)
		return (NULL);
	node = _bst_search(root, value);
	if (!node)
		return (root);
	if (node->left && node->right)
	{
		successor = inorder_successor(node);
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = successor;
			else
				node->parent->right = successor;
		}
		if (successor != node->right)
		{
			successor->parent->left = NULL;
			successor->right = node->right;
			successor->right->parent = successor;
		}
		successor->parent = node->parent;
		successor->left = node->left;
		successor->left->parent = successor;
		free(node);
		return (get_root(successor));
	}
	if (!node->left && !node->right)
	{
		if (node->parent && node == node->parent->left)
			node->parent->left = NULL;
		else if (node->parent)
			node->parent->right = NULL;
		successor = get_root(node);
		free(node);
		return (successor);
	}
	successor = node->left ? node->left : node->right;
	if (successor)
		successor->parent = node->parent;
	if (node->parent && node == node->parent->left)
		node->parent->left = successor ? successor : NULL;
	else if (node->parent)
		node->parent->right = successor ? successor : NULL;
	free(node);
	return (get_root(successor));
}

/**
 * inorder_successor - get the smallest node on the right tree
 * Description:
 * - if there's no right tree, get the node which is left child of its parent.
 * @node: node to get its in-order successor
 *
 * Return: successor or NULL
 */
bst_t *inorder_successor(binary_tree_t *node)
{
	bst_t *p;

	if (node->right)
		return (min_node(node->right));

	p = node->parent;
	while (p && node == p->right)
	{
		node = p;
		p = p->parent;
	}
	return (p);
}

/**
 * min_node - search minimum value on right subtree
 * @tree: pointer to a subtree
 *
 * Return: node comprises minimum value
 */
bst_t *min_node(bst_t *tree)
{
	if (tree && tree->left)
		return (min_node(tree->left));
	return (tree);
}

/**
 * _bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to node containing searched value, or NULL
 * if tree is NULL or value not found
 */
bst_t *_bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((binary_tree_t *)tree);
	return (tree->n > value ?
			_bst_search(tree->left, value) : _bst_search(tree->right, value));
}
/**
 * get_root - retrieves the root of a BT
 * @node: pointer to a node
 *
 * Return: root or NULL, if tree is empty
 */
bst_t *get_root(bst_t *node)
{
	if (!node)
		return (NULL);
	while (node->parent)
		node = node->parent;
	return (node);
}
