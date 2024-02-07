#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts Binary Max Heap to sorted array of integers
 * Description:
 * - Since we are using Max Heap,
 *   the returned array must be sorted in descending order.
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: address of the 1st element in the array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *arr;

	if (!heap)
	{
		*size = 0;
		return (NULL);
	}

	*size = binary_tree_size(heap);
	arr = malloc(sizeof(int) * (*size));
	for (i = 0; heap; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 *
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
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
