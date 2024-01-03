#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of a node
 *
 * Additional: if parent has a right-child, the new node takes its place
 * and the old right-child becomes the right-child of the new node.
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the newly created node
 * ------- NULL in failure OR if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode, *right;

	if (!parent)
		return (NULL);

	newNode = malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);

	right = parent->right;

	newNode->n = value;
	newNode->left = NULL;
	newNode->right = right;
	newNode->parent = parent;
	parent->right = newNode;

	if (right)
		right->parent = newNode;

	return (newNode);
}
