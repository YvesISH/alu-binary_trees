#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    size_t front = 0, back = 0;
    size_t max_nodes = 1024;
    const binary_tree_t **queue = malloc(max_nodes * sizeof(*queue));

    if (queue == NULL)
        return;

    queue[back++] = tree;

    while (front < back)
    {
        const binary_tree_t *node = queue[front++];

        func(node->n);

        if (node->left != NULL)
        {
            if (back >= max_nodes)
            {
                max_nodes *= 2;
                queue = realloc(queue, max_nodes * sizeof(*queue));
                if (queue == NULL)
                    return;
            }
            queue[back++] = node->left;
        }

        if (node->right != NULL)
        {
            if (back >= max_nodes)
            {
                max_nodes *= 2;
                queue = realloc(queue, max_nodes * sizeof(*queue));
                if (queue == NULL)
                    return;
            }
            queue[back++] = node->right;
        }
    }

    free(queue);
}
