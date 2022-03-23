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
 * print_level - function that goes through a binary tree
 * using level-order traversal and print each node
 * @node: pointer to the root node of the tree to print
 * @level: level of the node in the tree
 * @func: pointer to a function that take an int as parameter
 * Return: no return
 */
void print_level(const binary_tree_t *node, int level, void (*func)(int))
{
	if (node && func)
	{
		if (level == 1)
			func(node->n);
		if (level > 1)
		{
			print_level(node->left, level - 1, func);
			print_level(node->right, level - 1, func);
		}
	}
}

/**
 * binary_tree_levelorder - function that goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function that take an int as parameter
 * Return: no return
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0;
	size_t level = 0;

	height = binary_tree_height(tree);

	if (tree && func)
	{
		while ((int)height >= -1)
		{
			print_level(tree, level, func);
			level++;
			height--;
		}
	}
}
