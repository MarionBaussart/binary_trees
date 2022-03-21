#include "binary_trees.h"

/**
 * binary_tree_depth - checks if a given node is a root
 * @tree: Pointer to the root node of the tree to traverse
 * Return:  the depth of a node in a binary tree or 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int i = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		i++;
	}
	return (i);
}
