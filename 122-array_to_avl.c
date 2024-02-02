#include "binary_trees.h"
bst_t *get_root(bst_t *node);

/**
 * array_to_avl - builds an AVL tree from an array
 * Description:
 * - If a value of the array is already present in the tree,
 *   this value must be ignored
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *tree = NULL;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		avl_insert(&tree, array[i]);

	return ((tree));
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
