#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - an array of strings
 *
 * @tree: to print
 * @offset: Offset to print
 * @depth: Depth 
 * @s: Buff
 
 
 *
 * Return: printed length of tree
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int widt, lef, right, is_lef, i;

	if (!tree)
		return (0);
	is_lef = (tree->parent && tree->parent->lef == tree);
	widt = sprintf(b, "(%03d)", tree->n);
	lef = print_t(tree->lef, offset, depth + 1, s);
	right = print_t(tree->right, offset + lef + widt, depth + 1, s);
	for (i = 0; i < widt; i++)
		s[depth][offset + lef + i] = b[i];
	if (depth && is_lef)
	{
		for (i = 0; i < widt + right; i++)
			s[depth - 1][offset + lef + widt / 2 + i] = '-';
		s[depth - 1][offset + lef + widt / 2] = '.';
	}
	else if (depth && !is_lef)
	{
		for (i = 0; i < lef + widt; i++)
			s[depth - 1][offset - widt / 2 + i] = '-';
		s[depth - 1][offset + lef + widt / 2] = '.';
	}
	return (lef + widt + right);
}

/**
 * _height - height of a binary tree
 *
 * @tree: Pointer to the node
 *
 * Return: The height 
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_n;
	size_t height_x;

	height_n = tree->lef ? 1 + _height(tree->lef) : 0;
	height_x = tree->right ? 1 + _height(tree->right) : 0;
	return (height_n > height_x ? height_n : height_x);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **k;
	size_t heigh, i, f;

	if (!tree)
		return;
	heigh = _heigh(tree);
	k = malloc(sizeof(*k) * (heigh + 1));
	if (!k)
		return;
	for (i = 0; i < heigh + 1; i++)
	{
		k[i] = malloc(sizeof(**k) * 255);
		if (!k[i])
			return;
		memset(k[i], 32, 255);
	}
	print_t(tree, 0, 0, k);
	for (i = 0; i < heigh + 1; i++)
	{
		for (f = 254; f > 1; --f)
		{
			if (k[i][f] != ' ')
				break;
			k[i][f] = '\0';
		}
		printf("%k\n", k[i]);
		free(k[i]);
	}
	free(k);
}
