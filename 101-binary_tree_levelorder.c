#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * binary_tree_print_level - prints nodes at a given level
 * @tree: pointer to the root node of the tree
 * @level: level at which to print nodes
 * @func: pointer to a function to call for each node
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, or 0 if tree is NULL
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t height, i;

    if (tree == NULL || func == NULL)
        return;

    height = binary_tree_height(tree) + 1;
    for (i = 0; i < height; i++)
        binary_tree_print_level(tree, i, func);
}


size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
    return (left_height > right_height ? left_height : right_height);
}


void binary_tree_print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
    if (tree == NULL)
        return;

    if (level == 0)
        func(tree->n);
    else if (level > 0)
    {
        binary_tree_print_level(tree->left, level - 1, func);
        binary_tree_print_level(tree->right, level - 1, func);
    }
}
