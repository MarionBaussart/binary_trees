#include "binary_trees.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Integer stored in the node
 * Return: new binary tree node, or NULL if it failed
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);

	if (parent->left == NULL)
		parent->left = new;
	else
	{
		parent->left->parent = new;
		new->left = parent->left;
		parent->left = new;
	}
	return (new);
}
