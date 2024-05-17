#include "binary_trees.h"

/**
* binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is a valid BST, and 0 otherwise
* If tree is NULL, return 0
*/
int binary_tree_is_bst(const binary_tree_t *tree)
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

	/* if tree has two children, return 1 if both are BSTs */
	return (binary_tree_is_bst(tree->left) &&
		binary_tree_is_bst(tree->right));
}
