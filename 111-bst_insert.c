#include "binary_trees.h"
#include <stdio.h>

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = (*tree);

	printf("new create new->n: %d\n", new->n);

	if (new)
	{
		printf("new new->n: %d\n", new->n);
		if (value == (new->n))
		{
			free (new);
			return (*tree);
		}
		if (value > (new->n))
		{
			if (new->right)
			{
				printf("go right new->n: %d\n", new->n);
				new = new->right;
				bst_insert(&new, value);
			}
			else
				return (binary_tree_insert_right(new, value));
		}
		else if (value < new->n)
		{
			if (new->left)
			{
				printf("go left new->n: %d\n", new->n);
				new = new->left;
				bst_insert(&new, value);
			}
			else
				return (binary_tree_insert_left(new, value));
		}
	}
	return (binary_tree_node(new, value));
}

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

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);

	if (parent->right == NULL)
		parent->right = new;
	else
	{
		parent->right->parent = new;
		new->right = parent->right;
		parent->right = new;
	}
	return (new);
}
