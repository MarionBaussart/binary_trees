#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * or NULL if no common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *tmp;
	binary_tree_t *ancestor = NULL;

	if (first && second)
	{
		tmp = (binary_tree_t *)second;
		while (tmp)
		{
			if (tmp == first)
				return ((binary_tree_t *)first);
			tmp = tmp->parent;
		}
		tmp = (binary_tree_t *)second;
		if (first->parent)
		{
			if (binary_trees_ancestor(first->parent, tmp))
				ancestor = binary_trees_ancestor(first->parent, tmp);
			else
				ancestor = NULL;
		}
	}

	return (ancestor);
}
