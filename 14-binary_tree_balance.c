#include "binary_trees.h"

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

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t h_sub_tree_left = 0;
	size_t h_sub_tree_right = 0;
	int f_balance = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		h_sub_tree_left = binary_tree_height(tree->left) + 1;
	if (tree->right)
		h_sub_tree_right = binary_tree_height(tree->right) + 1;

	f_balance = h_sub_tree_left - h_sub_tree_right;

	return (f_balance);
}
