#include "binary_trees.h"

/**
 * binary_tree_postorder - function that goes through a binary tree
 * using post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function that take an int as parameter
 * Return: no return
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
		func(tree->n);
	}
}