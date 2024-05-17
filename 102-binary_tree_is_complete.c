#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * enqueue - Adds a node to the queue.
 * @queue: Pointer to the queue.
 * @rear: Pointer to the index of the rear of the queue.
 * @node: Node to add to the queue.
 */
void enqueue(binary_tree_t **queue, int *rear, binary_tree_t *node)
{
	queue[(*rear)++] = node;
}

/**
 * dequeue - Removes a node from the queue.
 * @queue: Pointer to the queue.
 * @front: Pointer to the index of the front of the queue.
 *
 * Return: The node removed from the queue.
 */
binary_tree_t *dequeue(binary_tree_t **queue, int *front)
{
	return queue[(*front)++];
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	int front, rear, found_non_full_node, queue_size;
	binary_tree_t *current;

	if (tree == NULL)
		return (0);

	/* Initialize variables */
	front = 0;
	rear = 0;
	found_non_full_node = 0;
	queue_size = 1024; /* Arbitrary large size for simplicity */
	queue = malloc(queue_size * sizeof(*queue));

	if (queue == NULL)
		return (0);

	/* Start with the root node */
	enqueue(queue, &rear, (binary_tree_t *)tree);

	while (front < rear)
	{
		current = dequeue(queue, &front);

		/* If we found a non-full node previously, all following nodes must be leaf nodes */
		if (found_non_full_node)
		{
			if (current->left != NULL || current->right != NULL)
			{
				free(queue);
				return (0);
			}
		}

		/* Enqueue left child */
		if (current->left)
			enqueue(queue, &rear, current->left);
		else
			found_non_full_node = 1;

		/* Enqueue right child */
		if (current->right)
		{
			/* If there's a right child without a left child, it's not complete */
			if (current->left == NULL)
			{
				free(queue);
				return (0);
			}
			enqueue(queue, &rear, current->right);
		}
		else
			found_non_full_node = 1;
	}

	free(queue);
	return (1);
}
