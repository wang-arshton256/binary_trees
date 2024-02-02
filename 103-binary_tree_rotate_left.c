#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates the binary tree to the Left.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *Pivote, *tmp;

    if (tree == NULL || tree->right == NULL)
        return (NULL);

    Pivote = tree->right;
    tmp = Pivote->left;
    Pivote->left = tree;
    tree->right = tmp;
    if (tmp != NULL)
        tmp->parent = tree;
    tmp = tree->parent;
    tree->parent = Pivote;
    Pivote->parent = tmp;
    if (tmp != NULL)
    {
        if (tmp->left == tree)
            tmp->left = Pivote;
        else
            tmp->right = Pivote;
    }

    return (Pivote);
}