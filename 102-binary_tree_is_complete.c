#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return:  measures the size of a binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t counter_l = 0;
	size_t counter_r = 0;

	if (tree == NULL)
		return (0);

	counter_l += binary_tree_size(tree->left);
	counter_r += binary_tree_size(tree->right);

	return (counter_l + counter_r + 1);
}

/**
 * check_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the node in the tree
 * @nb_nodes: number of nodes in the binary tree
 * Return: 1 if is complete, 0 otherwise or if tree is NULL
 */
int check_complete(const binary_tree_t *tree, int index, int nb_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= nb_nodes)
		return (0);

	return (check_complete(tree->left, 2 * index + 1, nb_nodes) &&
	check_complete(tree->right, 2 * index + 2, nb_nodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if is complete, 0 otherwise or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nb_nodes = 0;
	int index = 0;

	if (tree == NULL)
		return (0);

	nb_nodes = binary_tree_size(tree);

	return (check_complete(tree, index, nb_nodes));
}
