#include <stdlib.h>
#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 *
 * @root: Pointer to the root node of the tree for removing a node
 * @value: The value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree after removing the
 * desired value, and after rebalancing
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *successor;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}

		if (!root->left)
		{
			node = root->right;
			free(root);
			return (node);
		}

		if (!root->right)
		{
			node = root->left;
			free(root);
			return (node);
		}

		successor = root->right;

		while (successor->left)
			successor = successor->left;

		root->n = successor->n;
		root->right = avl_remove(root->right, successor->n);
	}

	if (!root)
		return (NULL);

	root->height = 1 + max(avl_height(root->left), avl_height(root->right));

	switch (avl_balance(root))
	{
		case 2:
			if (avl_balance(root->left) < 0)
				root->left = avl_rotate_left(root->left);
			return (avl_rotate_right(root));
		case -2:
			if (avl_balance(root->right) > 0)
				root->right = avl_rotate_right(root->right);
			return (avl_rotate_left(root));
		default:
			return (root);
	}
}

