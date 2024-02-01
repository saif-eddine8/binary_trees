#include "binary_trees.h"

/**
 * binary_tree_inorder -  binary tree to use in order traversa.
 * @tree: to traverse pointer to the root node of the tree.
 * @func: to call pointer to a function for each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
