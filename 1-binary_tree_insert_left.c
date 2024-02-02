#include "binary_trees.h"

/**
 * @value: Value to store in the new node.
 * @parent: Pointer to the node to insert the left-child in.
 *
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another within a binary tree.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a left-child, the new node
 *              takes its place and the old left-child is set as
 *              the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    if (parent == NULL)
        return (NULL);

    new = binary_tree_node(parent, value);
    if (new == NULL)
        return (NULL);

    if (parent->left != NULL)
    {
        new->left = parent->left;
        parent->left->parent = new;
    }
    parent->left = new;

    return (new);
}