#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: pointer to the node to look for its uncle
 *
 * Return: pointer to the uncle node if it exists,
 * or NULL in failure or if not found
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandfather, *father;

	if (!node || !(node->parent) || !(node->parent->parent))
		return (NULL);

	grandfather = node->parent->parent;
	father = node->parent;

	if (grandfather->left == father)
		return (grandfather->right);

	return (grandfather->left);
}
