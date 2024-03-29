#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @value: value to put in the new node.
 * @parent: Pointer to the parent of the node to create.
 *
 * Return: If an error occurs - NULL.
 * otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    new = malloc(sizeof(binary_tree_t));
    if (new == NULL)
        return (NULL);

    new->n = value;
    new->parent = parent;
    new->right = NULL;
    new->left = NULL;

    return (new);
}