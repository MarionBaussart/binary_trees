#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	else
		return (binary_tree_leaves(tree->left) +
				binary_tree_leaves(tree->right));
}

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
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: number
 * @y: power
 * Return: x^y, if y < 0 its return -1
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int nb_leaves = 0;
	size_t height = 0;

	if (tree == NULL)
		return (0);

	nb_leaves = binary_tree_leaves(tree);
	height = binary_tree_height(tree);

	if (nb_leaves == _pow_recursion(2, height))
		return (1);
	else
		return (0);
}
