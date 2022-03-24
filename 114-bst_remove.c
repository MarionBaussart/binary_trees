#include "binary_trees.h"

/**
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tree = root;

	tree = bst_search(root, value);

	if (tree == NULL)
	{
		free(tree);
	}
	if (tree && tree->right)
	{
		tree->n = tree->right->left->n;
		tree->right->left = NULL;
		free(tree->right->left);
	}
	if (tree && !tree->right && tree->left)
	{
		tree->n = tree->left->n;
		tree->left = NULL;
		free(tree->left);
	}
	return (root);
}

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
