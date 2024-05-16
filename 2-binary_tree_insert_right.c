#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts a node as the right-child of another node
* @parent: pointer to the node to insert the right-child in
* @value: value to store in the new node
* Return: pointer to the created node, or NULL on failure or if parent is NULL
* If parent already has a right-child, the new node must take its place,
* and the old right-child must be set as the right-child of the new node.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right_node = NULL;

	/* if parent is NULL, return NULL */
	if (parent == NULL)
		return (NULL);

	/* allocate memory for new node */
	new_right_node = malloc(sizeof(binary_tree_t));
	if (new_right_node == NULL)
		return (NULL);

	/* initialize new node */
	new_right_node->n = value;
	new_right_node->parent = parent;
	new_right_node->left = NULL;
	new_right_node->right = NULL;

	/* if parent already has a right-child, the new node must take its place */
	if (parent->right != NULL)
	{
		/* set the old right-child as the right-child of the new node */
		new_right_node->right = parent->right;
		/* set the new node as the right-child of the parent */
		parent->right->parent = new_right_node;
	}
	/* set the new node as the right-child of the parent */
	parent->right = new_right_node;

	/* return new node */
	return (new_right_node);
}
