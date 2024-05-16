#include "binary_trees.h"

/**
* binary_tree_sibling - finds the sibling of a node
* @node: pointer to the node to find the sibling
* Return: pointer to the sibling node, or NULL if node has no sibling
* If node is NULL, return NULL
* Author: Frank Onyema Orji
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* if node is NULL, return NULL */
	if (node == NULL)
		return (NULL);

	/* if node has no parent, return NULL */
	if (node->parent == NULL)
		return (NULL);

	/* if node is the left child of its parent, return right child */
	if (node->parent->left == node)
		return (node->parent->right);

	/* if node is the right child of its parent, return left child */
	if (node->parent->right == node)
		return (node->parent->left);

	/* if node has no sibling, return NULL */
	return (NULL);
}
