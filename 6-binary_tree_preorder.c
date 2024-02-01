#include "binary_trees.h"

/**
 * binary_tree_preorder - a binary tree using pre order traversa.
 * @tree: to traverse pointer to the root node of the tree .
 * @func: to call a function for each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
