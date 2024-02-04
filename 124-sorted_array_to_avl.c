#include "binary_trees.h"
avl_t *insert(avl_t *tree, avl_t *p, avl_t **node, int value);
avl_t *build_avl(avl_t **tree, avl_t *p, int *array, int first, int last);

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int first, last;
	avl_t *root = NULL;

	if (!array || size <= 0)
		return (NULL);

	if (size == 1)
		return (binary_tree_node(NULL, array[0]));

	first = 0, last = size - 1;
	root = NULL;

	build_avl(&root, root, array, first, last);

	return (root);
}

/**
 * build_avl - helper function to build avl tree from sorted array
 * @tree: double pointer to the root
 * @p: pointer to parent
 * @array: pointer to 1st element in the array
 * @first: 1st index
 * @last: last index
 *
 * Return: new tree
 */
avl_t *build_avl(avl_t **tree, avl_t *p, int *array, int first, int last)
{
	int mid;

	if (first > last)
		return (NULL);

	mid = first + (last - first) / 2;
	*tree = binary_tree_node(p, array[mid]);
	(*tree)->left = build_avl(&(*tree)->left, *tree, array, first,  mid - 1);
	(*tree)->right = build_avl(&(*tree)->right, *tree, array, mid + 1,  last);

	return (*tree);
}
