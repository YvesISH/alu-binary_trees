#include "binary_trees.h"

/**
 * max - Finds the maximum node in a tree.
 * @tree: The pointer to the root
 * Return: The node with the maximum value.
 * Author: Frank Onyema Orji
 */
heap_t *max(heap_t *tree)
{
	heap_t *curr_max, *left_max, *right_max;

	if (!tree->left)
		return (tree);
	left_max = max(tree->left);
	if (left_max->n > tree->n)
		curr_max = left_max;
	else
		curr_max = tree;
	if (tree->right)
	{
		right_max = max(tree->right);
		if (right_max->n > curr_max->n)
			curr_max = right_max;
		else
			curr_max = tree;
	}
	return (curr_max);
}

/**
 * recurse_extract - Recursively extracts the max from the tree.
 * @tree: The pointer to the root of the tree.
 */
void recurse_extract(heap_t *tree)
{
	heap_t *sub_max, *right_max = NULL;

	if (!tree->left)
		return;
	sub_max = max((tree)->left);
	if (tree->right)
		right_max = max(tree->right);
	if (right_max && right_max->n > sub_max->n)
		sub_max = right_max;
	tree->n = sub_max->n;
	if (!sub_max->left)
	{
		if (sub_max->parent && sub_max->parent->left == sub_max)
			sub_max->parent->left = NULL;
		if (sub_max->parent && sub_max->parent->right == sub_max)
			sub_max->parent->right = NULL;
		free(sub_max);
	}
	else
		recurse_extract(sub_max);
}

/**
 * heap_extract - Extracts the root from a Binary Hip.
 * @root: The pointer to the root of the tree.
 * Return: The value of the extracted .
 */
int heap_extract(heap_t **root)
{
	int value;

	if (!*root)
		return (0);
	value = (*root)->n;
	if (!(*root)->left)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
		return (value);
	}
	recurse_extract(*root);
	return (value);
}