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

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	if (parent->left == NULL)
	{
		binary_tree_node(parent, value);
	}
	else
	{
		new->parent = parent;
		new->n = value;
		new->right = NULL;
		parent->left->parent = new;
		new->left = parent->left;
		parent->left = new;

	}
	return (new);
}
