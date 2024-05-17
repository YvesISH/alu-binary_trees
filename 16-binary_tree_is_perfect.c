#include "binary_trees.h"

/**
 * get_depth - Gets the depth of the leftmost node.
 * @tree: Pointer to the root node of the tree to check.
 * Return: Depth of the leftmost node.
 */
int get_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}

/**
 * is_perfect_recursive - .....
 * @tree: Pointer to the root node of the tree to check.
 * @depth: Depth of the tree.
 * @level: Current level in the tree.
 * Return: 1 if tree is perfect, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is perfect, otherwise 0.
 * If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = get_depth(tree);

	return (is_perfect_recursive(tree, depth, 0));
}
