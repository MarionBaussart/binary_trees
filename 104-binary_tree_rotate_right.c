#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to check
 * Return: tree or NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;

	if (tree->parent)
		tmp = tree->parent;

	if (tree && tree->left)
	{
		tree->parent = tree->left;
		if (tree->left->right)
		{
			tree->left = tree->parent->right;
			tree->left->parent = tree;
		}
		else
			tree->left = NULL;
		tree->parent->right = tree;

		if (tmp)
		{
			if (tree->parent->n > tmp->n)
				tmp->right = tree->parent;
			else if (tree->parent->n < tmp->n)
				tmp->left = tree->parent;
			tree->parent->parent = tmp;
		}
		else
			tree->parent->parent = NULL;

		return (tree->parent);
	}
	else
		return (NULL);
}
