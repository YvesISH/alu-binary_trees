#include "binary_trees.h"

/**
 * is_bst_util - Recursive utility function to check if a binary tree is a valid BST
 * @tree: A pointer to the root node of the tree
 * @prev: A pointer to the previous node's value
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int is_bst_util(const binary_tree_t *tree, int *prev)
{
	if (tree != NULL)
	{
		if (!is_bst_util(tree->left, prev))
			return (0);

		if (*prev != -1 && tree->n <= *prev)
			return (0);

		*prev = tree->n;

		return is_bst_util(tree->right, prev);
	}

	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = -1; /* Store the previous node's value */

	if (tree == NULL)
		return (0);

	return is_bst_util(tree, &prev);
}
