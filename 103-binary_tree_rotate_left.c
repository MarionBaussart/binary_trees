#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to check
 * Return: tree or NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;

	if (tree && tree->parent)
		tmp = tree->parent;

	if (tree && tree->right)
	{
		tree->parent = tree->right;
		if (tree->right->left)
		{
			tree->right = tree->parent->left;
			tree->right->parent = tree;
		}
		else
			tree->right = NULL;
		tree->parent->left = tree;

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
