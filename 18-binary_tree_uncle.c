#include "binary_trees.h"

/**
* binary_tree_uncle - finds the uncle of a node
* @node: pointer to the node to find the uncle
* Return: pointer to the uncle node, or NULL if node has no uncle
* If node is NULL, return NULL
* Author: Frank Onyema Orji
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* if node is NULL, return NULL */
	if (node == NULL)
		return (NULL);

	/* if node has no parent, return NULL */
	if (node->parent == NULL)
		return (NULL);

	/* if node has no grandparent, return NULL */
	if (node->parent->parent == NULL)
		return (NULL);

	/* if node's parent is the left child of its parent */
	/* return right child of node's grandparent */
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	/* if node's parent is the right child of its parent */
	/* return left child of node's grandparent */
	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);

	/* if node has no uncle, return NULL */
	return (NULL);
}
