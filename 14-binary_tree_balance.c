#include "binary_trees.h"

size_t height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root of the tree to measure
 *
 * Return: the tree's balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (height(tree->left) - height(tree->right));
}

/**
 * height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: height of the tree, 0 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
		size_t left = 1, right = 1;

	if (!tree)
		return (0);

	if (tree->left)
		left = height(tree->left) + 1;
	if (tree->right)
		right = height(tree->right) + 1;

	return ((right > left) ? right : left);
}
