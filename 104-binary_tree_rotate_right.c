#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to check
 * Return: tree or NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree && tree->left)
	{
		tree->parent = tree->left;
		if (tree->left->right)
			tree->left = tree->parent->right;
		else
			tree->left = NULL;
		tree->parent->right = tree;
		tree->parent->parent = NULL;
		return (tree->parent);
	}
	else
		return(NULL);
}
