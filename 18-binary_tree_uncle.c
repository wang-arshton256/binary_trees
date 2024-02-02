#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the Uncle of the node
 *                     in the binary tree.
 * @node: pointer to the node to find the Uncle of.
 *
 * Return: If node is NULL or has no Uncle, NULL.
 *         Otherwise, a pointer to the Uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL ||
        node->parent == NULL ||
        node->parent->parent == NULL)
        return (NULL);
    if (node->parent->parent->left == node->parent)
        return (node->parent->parent->right);
    return (node->parent->parent->left);
}