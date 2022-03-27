#include "binary_trees.h"
#include <stdio.h>

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = bst_insert(tree, value);
	avl_t *tmp = node;

	if (*tree == NULL)
		*tree = node;

	while (tmp)
	{
		if (binary_tree_balance(tmp) > 1 && tmp->left && tmp->left->right)
		{
			binary_tree_rotate_left(tmp->left);
			binary_tree_rotate_right(tmp);
		}

		else if (binary_tree_balance(tmp) > 1 && tmp->left && tmp->left->left)
			binary_tree_rotate_right(tmp);

		else if (binary_tree_balance(tmp) < -1 && tmp->right && tmp->right->left)
		{
			binary_tree_rotate_right(tmp->right);
			binary_tree_rotate_left(tmp);
		}
		else if (binary_tree_balance(tmp) < -1 && tmp->right && tmp->right->right)
			binary_tree_rotate_left(tmp);

		if (tmp->parent == NULL)
			*tree = tmp;
		tmp = tmp->parent;
	}
	return (node);
}

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	node = (*tree);

	while (node)
	{
		if (value == (node->n))
			return (NULL);

		if (value > (node->n))
		{
			if (node->right)
				node = node->right;
			else
			{
				node->right = binary_tree_node(node, value);
				return (node->right);
			}
		}
		else if (value < node->n)
		{
			if (node->left)
				node = node->left;
			else
			{
				node->left = binary_tree_node(node, value);
				return (node->left);
			}
		}
	}

	return (NULL);
}
