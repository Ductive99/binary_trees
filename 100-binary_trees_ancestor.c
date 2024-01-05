#include "binary_trees.h"

/**
 * binary_tree_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor if it exists,
 * or NULL otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (first == second)
		return ((binary_tree_t *)first);
	else if (depth_first > depth_second)
		return (binary_trees_ancestor(first->parent, second));
	else if (depth_first < depth_second)
		return (binary_trees_ancestor(first, second->parent));
	else
		return (binary_trees_ancestor(first->parent, second->parent));
}

/**
 * binary_tree_depth - measures the depth of a node
 *
 * @tree: pointer to the node to measure its depth
 *
 * Return: its depth, 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !(tree->parent))
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}
