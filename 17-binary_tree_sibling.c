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
