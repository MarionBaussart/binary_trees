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
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full, 0 otherwise or if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t nb_leaves = 0;

	nb_leaves = binary_tree_leaves(tree);

	if (tree == NULL)
		return (0);

	if (nb_leaves % 2 == 0)
		return (1);
	else
		return (0);
}
