#include "binary_trees.h"

/**
 * binary_tree_node - that Creates a binary tree node.
 * @parent: to create a pointer to the parent's node .
 * @value: to put the value in the new node.
 *
 * Return: If an error occurs  NULL.
 *         Otherwise a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new_n->n = value;
	new_n->parent = parent;
	new_n->left = NULL;
	new_n->right = NULL;

	return (new_n);
}
