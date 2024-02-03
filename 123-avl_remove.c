#include "binary_trees.h"
avl_t *search(const bst_t *tree, int value);
avl_t *remove_avl(avl_t *tree, int value);
bst_t *get_root(bst_t *node);
void repair_balance(avl_t **tree);

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
	(void)node;

	if (!root)
		return (NULL);
	node = remove_avl(root, value);

	return (node);
}

/**
 * remove_avl - helper function to find the note and remove
 * Desctiption: it also maintains the balance factor
 * @tree:
 * @value:
 *
 * Return: new root
 */
avl_t *remove_avl(avl_t *tree, int value)
{
	avl_t *node = NULL, *successor = NULL, *p;
	int bf;
	(void)bf;
	(void)p;

	if (!tree)
		return (NULL);
	if (tree->n > value)
		node = remove_avl(tree->left,  value);
	else if (tree->n < value)
		node = remove_avl(tree->right,  value);
	else
		node = tree;

	if (!node)
		/* node not found */
		return (NULL);

	if (node->n != value)
		/* if it's not the searched node do nothing */
		return (node);

	if (node->left && node->right)
	{
		successor = inorder_successor(node);
		p = successor->parent;
		node->n = successor->n;
		if (successor->left || successor->right)
			return (remove_avl(successor,  successor->n));
		if (p->left == successor)
			p->left = NULL;
		else
			p->right = NULL;
		free(successor);

		successor = NULL;
		repair_balance(&p);
		return (node);
	}
	if (!node->left && !node->right)
	{
		/* no children */
		if (node->parent && node == node->parent->left)
			node->parent->left = NULL;
		else if (node->parent)
			node->parent->right = NULL;

		p = node->parent;
		free(node);
		node = NULL;
		repair_balance(&p);
		/* 		return (successor); */
		return (node);
	}
	/* node w/ one child, successor is leaf */
	successor = node->left ? node->left : node->right;
	node->n = successor->n;
	p = successor->parent;
	if (node->left == successor)
		node->left = NULL;
	else
		node->right = NULL;

	free(successor);

	repair_balance(&p);
	successor = NULL;
	return (node);
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
 * examine_balance - helper to rebalance
 * @tree:
 *
 */
void repair_balance(avl_t **p)
{
	int bf = 0;
/**
 * 	avl_t *tree = *p;
 * 	(void)tree;
 */

	if (!p || !*p)
		return;
	bf = binary_tree_balance((const binary_tree_t *)*p);

	if (bf > 1)
	{
		/* perform LL rotation */
		printf("LL = %d\n", (*p)->n);
		if (*p == (*p)->parent->left)
			(*p)->parent->left = (binary_tree_rotate_right((binary_tree_t *)*p));
		else
			(*p)->parent->right = (binary_tree_rotate_right((binary_tree_t *)*p));

		printf("LL = %d\n", (*p)->n);
	}
	if (bf < -1)
	{
		printf("RR = %d\n", (*p)->n);
		/* perform RR rotation */
		if (*p == (*p)->parent->right)
			(*p)->parent->right = (binary_tree_rotate_left((binary_tree_t *)*p));
		else
			(*p)->parent->left = (binary_tree_rotate_left((binary_tree_t *)*p));

		printf("p = %d, pr = %d\n", (*p)->parent->n, (*p)->parent->right->n);
	}

	if ((*p)->parent)
		repair_balance(&(*p)->parent);
}
