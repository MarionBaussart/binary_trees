#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return:  measures the size of a binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t counter_l = 0;
	size_t counter_r = 0;

	if (tree == NULL)
		return (0);

	counter_l += binary_tree_size(tree->left);
	counter_r += binary_tree_size(tree->right);

	return (counter_l + counter_r + 1);
}
