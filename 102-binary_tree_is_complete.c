#include "binary_trees.h"
/**
 * isCompleted - checks if a tree is completed
 * @root : racine del'arbre binaire
 * @ind : index
 * @cal : taille of the tree
 * Return : index if completed , otherwise 0
*/
int isCompleted(const binary_tree_t *root, unsigned long cal, long unsigned int ind)
{
	if (!root)
		return (1);
	if (ind >= cal)
		return (0);
	return (isCompleted(root->left, 2 * ind + 1, cal)
			&& isCompleted(root->right, 2 * ind + 2, cal));
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	unsigned long cal = binary_tree_size((const binary_tree_t *)tree);

	if (!tree)
		return (0);
	return (isCompleted(tree, cal, 0));
}
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
