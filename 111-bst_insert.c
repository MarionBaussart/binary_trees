#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to check
 * Return: tree or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t **tmp;
	tmp = (bst_t **)tree;
	if (tree)
	{
		if (value > (*tree)->n)
		{
			if ((*tree)->right)
				bst_insert(tree, value);
		}
		else if (value > (*tree)->n)
		{
			if ((*tree)->left)
				bst_insert(tree, value);
		}
	}
	*tree = binary_tree_node(*tmp, value);
	return (*tree);
}
