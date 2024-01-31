#include "binary_trees.h"
/**
 * 
 * 
*/
int isCompleted(const binary_tree_t *root, unsigned long cal, int ind)
{
    if (!root)
        return (1);

    if (ind >= cal)
        return (0);

    return (isCompleted(root->left, 2 * ind + 1, cal) && isCompleted(root->right, 2 * ind + 2, cal));
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
        return (NULL);
    return isCompleted(tree, cal, 0);
}


