#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given node is a root
 * @node: Pointer to the node to check
 * Return: 1 if node is a root, otherwise 0
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
	    binary_tree_inorder(tree->left, func);
		func(tree->n);
    	binary_tree_inorder(tree->right, func);
	}
}