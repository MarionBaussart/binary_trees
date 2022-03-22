#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, 0 if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if (tree->left != NULL && tree->right == NULL)
		{
			return (0);
		}
		else if (tree->right != NULL && tree->left == NULL)
		{
			return (0);
		}
		else if (tree->left && tree->right)
		{
			binary_tree_is_full(tree->left);
			binary_tree_is_full(tree->right);
			return (1);
		}
		else
		{
			return (1);
		}
		printf("un truc");
		
	}
	return (0);
}
