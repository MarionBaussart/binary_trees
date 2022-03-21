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
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	if (parent->right == NULL)
	{
		binary_tree_node(parent, value);
	}
	else
	{
		new->parent = parent;
		new->n = value;
		new->left = NULL;
		parent->right->parent = new;
		new->right = parent->right;
		parent->right = new;

	}
	return (new);
}
