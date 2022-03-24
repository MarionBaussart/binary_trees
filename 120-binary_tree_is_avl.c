#include "binary_trees.h"
#include "16-binary_tree_is_perfect.c"

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * (AVL tree if BST, balance <= 1, left and right subtrees must also
 * be AVL trees)
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise or if tree is NULL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height = 0, level = 0;

	if (tree == NULL)
		return (0);

	if (binary_tree_is_bst(tree) != 1)
		return (0);

	height = binary_tree_height(tree);
	while (level < height)
	{
		if (binary_tree_is_perfect(tree) != 1)
			return (0);

		level++;
	}

	if (binary_tree_balance(tree) <= -1 && binary_tree_balance(tree) >= 1)
		return (0);

	return (1);
}

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
