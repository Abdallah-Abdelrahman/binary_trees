#include "binary_trees.h"
avl_t *remove_avl(avl_t *tree, int value);
bst_t *_root(bst_t *node);
bst_t *_min(bst_t *tree);
bst_t *_inorder_successor(binary_tree_t *node);

/**
 * avl_remove - removes a node from an AVL tree
 * Descriptoin:
 * - the node containing a value equals to value must be removed and freed.
 * - If the node to be deleted has two children,
 *   it must be replaced with its first in-order successor.
 * - After deletion of the desired node,
 *   the tree must be rebalanced if necessary.
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree,
 * after removing the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node = root;

	if (!root)
		return (NULL);
	node = remove_avl(root, value);

	return (node);
}

/**
 * remove_avl - helper function to find the note and remove
 * Desctiption: it also maintains the balance factor
 * @tree: pointer to root
 * @value: value of the node to remove
 *
 * Return: new root
 */
avl_t *remove_avl(avl_t *tree, int value)
{
	avl_t *node = NULL, *successor = NULL, *p = NULL;
	(void)p;

	if (!tree)
		return (tree);
	if (tree->n > value)
		node = remove_avl(tree->left,  value);
	else if (tree->n < value)
		node = remove_avl(tree->right,  value);
	else
		node = tree;

	if (!node)
		/* node not found */
		return (_root(tree));

	if (node->n != value)
		/* if it's not the searched node do nothing */
		return (node);

	if (node->left && node->right)
	{
		successor = _inorder_successor(node);
/*		p = successor->parent; */
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
		repair_balance(&successor);
		free(node);
		return (_root(successor));
	}
	if (!node->left && !node->right)
	{
		if (node->parent && node == node->parent->left)
			node->parent->left = NULL;
		else if (node->parent)
			node->parent->right = NULL;
/*		p = node->parent; */
		repair_balance(&node);
		successor = _root(node);
		free(node);
		return (successor);
	}
	/* node w/ one child, successor is leaf */
	successor = node->left ? node->left : node->right;
	successor->parent = node->parent;
/*	p = successor->parent; */
	if (node->parent && node == node->parent->left)
		node->parent->left = successor;
	else if (node->parent)
		node->parent->right = successor;

	repair_balance(&successor);
	free(node);
	return (_root(successor));
}

/**
 * _inorder_successor - get the smallest node on the right tree
 * Description:
 * - if there's no right tree, get the node which is left child of its parent.
 * @node: node to get its in-order successor
 *
 * Return: successor or NULL
 */
bst_t *_inorder_successor(binary_tree_t *node)
{
	bst_t *p;

	if (node->right)
		return (_min(node->right));

	p = node->parent;
	while (p && node == p->right)
	{
		node = p;
		p = p->parent;
	}
	return (p);
}

/**
 * _min - search minimum value on right subtree
 * @tree: pointer to a subtree
 *
 * Return: node comprises minimum value
 */
bst_t *_min(bst_t *tree)
{
	if (tree && tree->left)
		return (_min(tree->left));
	return (tree);
}

/**
 * repair_balance - helper to rebalance
 * @p: double pointer to the node
 *
 * Return: Nothing
 */
void repair_balance(avl_t **p)
{
	int bf = 0;
	avl_t *tree = *p;

	if (!tree)
		return;
	bf = binary_tree_balance(*p);


	if (bf > 1 && binary_tree_balance(tree->left) >= 0)
	{
		/* perform LL rotation */
		if (!tree->parent)
			tree = (binary_tree_rotate_right(*p));

		else if (tree == tree->parent->left)
			tree->parent->left = (binary_tree_rotate_right(*p));
		else if (tree->parent)
			tree->parent->right = (binary_tree_rotate_right(*p));


	}
	if (bf < -1 && binary_tree_balance(tree->right) <= 0)
	{
		/* perform RR rotation */
		if (!tree->parent)
			tree = binary_tree_rotate_left(tree);

		else if (tree->parent && tree == tree->parent->left)
			tree->parent->left = (binary_tree_rotate_left(*p));
		else if (tree->parent)
			tree->parent->right = (binary_tree_rotate_left(*p));


	}

	if (bf > 1 && binary_tree_balance(tree->left) < 0)
	{
		/* perform LR rotation */
		tree->left = binary_tree_rotate_left(tree->left);
		if (tree == tree->parent->left)
			tree->parent->left = (binary_tree_rotate_right(*p));
		else
			tree->parent->right = (binary_tree_rotate_right(*p));
	}
	if (bf < -1 && binary_tree_balance(tree->right) > 0)
	{
		/* perform RL rotation */
		tree->right = binary_tree_rotate_right(tree->right);
		if (tree == tree->parent->left)
			tree->parent->left = (binary_tree_rotate_left(*p));
		else
			tree->parent->right = (binary_tree_rotate_left(*p));
	}

	repair_balance(&(*p)->parent);
}
/**
 * _root - retrieves the root of a BT
 * @node: pointer to a node
 *
 * Return: root or NULL, if tree is empty
 */
bst_t *_root(bst_t *node)
{
	if (!node)
		return (NULL);
	while (node->parent)
		node = node->parent;
	return (node);
}
