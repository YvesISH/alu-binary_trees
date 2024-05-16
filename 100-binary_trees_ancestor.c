#include "binary_trees.h"

/**
* binary_tree_is_full - checks if a binary tree is full
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is full, 0 if tree is NULL or not full
* Author: Frank Onyema Orji
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* if tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* if tree has no children, return 1 */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* if tree has one child, return 0 */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* if tree has two children, return 1 if both are full */
	return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
}
