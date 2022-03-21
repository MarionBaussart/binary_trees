#include "binary_trees.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_node - creates a binary tree node
 * @node: Pointer to the node to check
 * Return: new binary tree node, or NULL if it failed
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return(0);
	}
	if (node->left == NULL && node->right == NULL)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
