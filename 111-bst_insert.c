#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to check
 * Return: tree or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = (*tree);

	if (tmp)
	{
		if (value == (tmp->n))
			return (tmp);
		if (value > (tmp->n))
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				bst_insert(&tmp, value);
			}
			else
				return (binary_tree_insert_right(tmp, value));
		}
		else if (value < tmp->n)
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				bst_insert(&tmp, value);
			}
			else
				return (binary_tree_insert_left(tmp, value));
		}
	}
	return (binary_tree_node(tmp, value));
	free (tmp);
	return (NULL);

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
