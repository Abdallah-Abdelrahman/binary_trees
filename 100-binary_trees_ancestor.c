#include "binary_trees.h"

/**
 * binary_trees_ancestor - function  that finds the lowest common ancestor of two nodes
 * 
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second){
    size_t depfirst;
    size_t depsecond;

	if (!first || !second)
		return (NULL);

	depfirst = binary_tree_depth(first);
	depsecond = binary_tree_depth(second);

	if (first == second)
		return ((binary_tree_t *)first);
	else if (depfirst > depsecond)
		return (binary_trees_ancestor(first->parent, second));
	else if (depfirst < depsecond)
		return (binary_trees_ancestor(first, second->parent));
	else
		return (binary_trees_ancestor(first->parent, second->parent));

}