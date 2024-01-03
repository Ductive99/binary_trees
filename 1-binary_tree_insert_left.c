#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of a node
 *
 * Additional: if parent has a left-child, the new node takes its place
 * and the old left-child becomes the left-child of the new node.
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the newly created node
 * ------- NULL in failure OR if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode, *left;

	if (!parent)
		return (NULL);

	left = parent->left;

	newNode = malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);

	newNode->n = value;
	newNode->left = left;
	newNode->right = NULL;
	newNode->parent = parent;
	parent->left = newNode;

	if (left)
		left->parent = newNode;

	return (newNode);
}
