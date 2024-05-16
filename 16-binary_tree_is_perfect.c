#include "binary_trees.h"

/**
* binary_tree_uncle - finds the uncle of a node
* @node: pointer to the node to find the uncle
* Return: pointer to the uncle node, or NULL if node has no uncle
* If node is NULL, return NULL
* Arthor: Frank Onyema Orji
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, otherwise 0
 * If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height = binary_tree_height(tree);
    size_t expected_leaves = 1 << height;

    return (binary_tree_is_full(tree) && binary_tree_leaves(tree) == expected_leaves);
}
