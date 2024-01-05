#include "binary_trees.h"

size_t size(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);
size_t power(size_t base, size_t exponent);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (size(tree) + 1 == power(2, height(tree) + 1))
		return (1);

	return (0);
}

/**
 * size - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: tree size, 0 if tree is NULL
 */
size_t size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (size(tree->left) + size(tree->right) + 1);
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
	double left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left = height(tree->left) + 1;
	if (tree->right)
		right = height(tree->right) + 1;

	return ((right > left) ? right : left);
}

/**
 * power - exponentiation funcion
 *
 * @base: base of the logarithm
 * @exponent: exponent
 *
 * Return: base to the power of the exponent
 */
size_t power(size_t base, size_t exponent)
{
	size_t i, result = base;

	if (base <= 0 || exponent <= 0)
		return (0);

	for (i = 1; i < exponent; i++)
		result *= base;

	return (result);
}
