#include "binary_trees.h"
bst_t *_bst_insert(bst_t *tree, int value);
bst_t *bst_insert(bst_t **tree, int value);

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
	int balance;

	if (!*tree)
		/* root */
		return (*tree = binary_tree_node(NULL, value));

	node = bst_insert(tree, value);
	balance = binary_tree_balance(node);

	/* Left Left Case */
	if (balance > 1 && value < node->left->n)
		(binary_tree_rotate_right(node));

	/* Right Right Case */
	else if (balance < -1 && value > node->right->n)
		binary_tree_rotate_left(node);

	/* Left Right Case */
	else if (balance > 1 && value > node->left->n)
	{
		node->left =  binary_tree_rotate_left(node->left);
		binary_tree_rotate_right(node);
	}

	/* Right Left Case */
	else if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		binary_tree_rotate_left(node);
	}
	return (node);
}

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
		return (tree->right = binary_tree_node(tree, value));
	if (tree->n > value && !tree->left)
		return (tree->left = binary_tree_node(tree, value));
	return (tree->n > value ?
			_bst_insert(tree->left, value) : _bst_insert(tree->right, value));
}

