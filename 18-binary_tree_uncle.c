#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node,
 * NULL if node is NULL or the parent is NULL or if node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left && node->n != node->parent->left->n)
		return (node->parent->left);
	if (node->parent->right && node->n != node->parent->right->n)
		return (node->parent->right);
	else
		return (NULL);
}

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node,
 * NULL if node is NULL or if node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	if (node == NULL)
		return (NULL);

	uncle = binary_tree_sibling(node->parent);

	return (uncle);
}
