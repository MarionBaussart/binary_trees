#include "binary_trees.h"
#include <limits.h>

/**
 * bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @min: node min
 * @max: node max
 * Return:  1 if tree is a valid BST, and 0 otherwise or if tree is NULL
 */
int bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < max && tree->n > min)
		return (bst(tree->left, min, tree->n) && bst(tree->right, tree->n, max));
	else
		return (0);
}


/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return:  1 if tree is a valid BST, and 0 otherwise or if tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst(tree, INT_MIN, INT_MAX));
}
