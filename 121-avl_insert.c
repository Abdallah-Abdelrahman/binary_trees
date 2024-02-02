#include "binary_trees.h"
avl_t *insert(avl_t *tree, avl_t *p, int value);

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
	avl_t *node;

	if (!*tree)
		/* root */
		return (*tree = binary_tree_node(NULL, value));

	node = insert(*tree, *tree, value);
	return (node);
}
/**
 * insert - helper function to insert in avl
 * @tree: root
 * @p: parent node
 * @value: value of node to insert
 *
 * Return: the new tree
 */
avl_t *insert(avl_t *tree, avl_t *p, int value)
{
	int bf;

	if (!tree)
		return (binary_tree_node(p, value));
	else if (value < tree->n)
		tree->left = insert(tree->left, tree, value);
	else if (value > tree->n)
		tree->right = insert(tree->right, tree, value);

	bf = binary_tree_balance(tree);
	if (bf > 1 && value < tree->left->n)
		/* perform LL rotation */
		return (binary_tree_rotate_right(tree));
	if (bf < -1 && value > tree->right->n)
		/* perform RR rotation */
		return (binary_tree_rotate_left(tree));

	if (bf > 1 && value > tree->left->n)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	if (bf < -1 && value < tree->right->n)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}
	return (tree);
}
