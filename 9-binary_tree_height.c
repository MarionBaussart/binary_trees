#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	if (tree)
	{
		height_left = binary_tree_height(tree->left) + 1;
		height_right = binary_tree_height(tree->right) + 1;
	}
	
	if (height_left > height_right)
		return (height_left);
	else
		return (height_right);
}
