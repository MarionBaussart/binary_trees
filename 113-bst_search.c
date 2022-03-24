#include "binary_trees.h"

/**
 * bst_search - function that searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: return a pointer to the node containing a value equals to value,
 * NULL if tree is NULL or if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree)
	{
		if (value == tree->n)
			return ((bst_t *)tree);

		if (tree && value > tree->n)
			tree = tree->right;

		if (tree && value < tree->n)
			tree = tree->left;
	}

	/* nothing founded */
	return (NULL);
}
