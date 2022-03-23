#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 0 or 1
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (tree)
	{
		if (tree->right->left)
		{
			tmp = (binary_tree_t *)tree->right;

			tree->right = tmp->left;
			tree->right->parent = tree;
		
			tmp->left = tree;
			tmp->parent = tree->parent;
			tree->parent = tmp;
			

	}
	return (tree);
}
