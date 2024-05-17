#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise or if tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    // Initialize a queue for level order traversal
    binary_tree_t **queue;
    int front = 0, rear = 0, found_non_full_node = 0;
    int queue_size = 1024; // Arbitrary large size for simplicity
    queue = malloc(queue_size * sizeof(*queue));

    if (queue == NULL)
        return (0);

    // Start with the root node
    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        binary_tree_t *current = queue[front++];

        // If we found a non-full node previously, all following nodes must be leaf nodes
        if (found_non_full_node)
        {
            if (current->left != NULL || current->right != NULL)
            {
                free(queue);
                return (0);
            }
        }

        // Enqueue left child
        if (current->left)
        {
            queue[rear++] = current->left;
        }
        else
        {
            // Mark that we've found a non-full node
            found_non_full_node = 1;
        }

        // Enqueue right child
        if (current->right)
        {
            // If there's a right child without a left child, it's not complete
            if (current->left == NULL)
            {
                free(queue);
                return (0);
            }
            queue[rear++] = current->right;
        }
        else
        {
            // Mark that we've found a non-full node
            found_non_full_node = 1;
        }
    }

    free(queue);
    return (1);
}
