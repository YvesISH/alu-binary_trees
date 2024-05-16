#include "binary_trees.h"

/**
* binary_tree_insert_left - inserts a node as the left-child of another node
* @parent: pointer to the node to insert the left-child in
* @value: value to store in the new node
* Return: pointer to the created node, or NULL on failure or if parent is NULL
* If parent already has a left-child, the new node must take its place,
* and the old left-child must be set as the left-child of the new node.
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left_node = NULL;

	/* if parent is NULL, return NULL */
	if (parent == NULL)
		return (NULL);

	/* allocate memory for new node */
	new_left_node = malloc(sizeof(binary_tree_t));
	if (new_left_node == NULL)
		return (NULL);

	/* initialize new node */
	new_left_node->n = value;
	new_left_node->parent = parent;
	new_left_node->left = NULL;
	new_left_node->right = NULL;

	/* if parent already has a left-child, the new node must take its place */
	if (parent->left != NULL)
	{
		/* set the old left-child as the left-child of the new node */
		new_left_node->left = parent->left;
		/* set the new node as the left-child of the parent */
		parent->left->parent = new_left_node;
	}
	/* set the new node as the left-child of the parent */
	parent->left = new_left_node;

	/* return new node */
	return (new_left_node);
}
