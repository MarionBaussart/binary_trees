#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 0 or 1
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
<<<<<<< HEAD
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
=======
	Pivot = tree→CO
	tree→CO = tree→right
	Pivot→CR = tree
	tree = Pivot
>>>>>>> 78b26a67d8c289686366c31e154bb5599135b2e1
}
