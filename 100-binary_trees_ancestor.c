#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest ancestor
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest ancestor, or NULL
 * Author: Frank Onyema Orji
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	const binary_tree_t *tmp;
	int depth_first = 0, depth_second = 0;

	if (!first || !second)
		return (NULL);

	tmp = first;
	while (tmp)
	{
		depth_first++;
		tmp = tmp->parent;
	}

	tmp = second;
	while (tmp)
	{
		depth_second++;
		tmp = tmp->parent;
	}

	for (; depth_first > depth_second; depth_first--)
		first = first->parent;
	for (; depth_second > depth_first; depth_second--)
		second = second->parent;

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
