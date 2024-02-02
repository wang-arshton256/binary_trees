#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - calculates the height of a binary tree
 * @tree: the pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
    size_t height_L = 0;
    size_t height_R = 0;

    if (!tree)
        return (0);

    if (tree->left)
        height_L = 1 + tree_height(tree->left);

    if (tree->right)
        height_R = 1 + tree_height(tree->right);

    if (height_L > height_R)
        return (height_L);
    return (height_R);
}
/**
 * tree_size_h - calculates the sum of the heights of a binary tree
 * @tree: the pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
    size_t height_L = 0;
    size_t height_R = 0;

    if (!tree)
        return (0);

    if (tree->left)
        height_L = 1 + tree_size_h(tree->left);

    if (tree->right)
        height_R = 1 + tree_size_h(tree->right);

    return (height_L + height_R);
}

/**
 * _pre_order - checks through the binary tree using a pre-order traversal
 * @tree: the pointer to the root node of the tree to traverse
 * @node: will be the last node in the traverse
 * @height: height of the tree
 *
 * Return: No Return
 */
void _pre_order(heap_t *tree, heap_t **node, size_t height)
{
    if (!tree)
        return;

    if (!height)
        *node = tree;
    height--;

    _pre_order(tree->left, node, height);
    _pre_order(tree->right, node, height);
}

/**
 * heapyfy - heapyfies the max binary heap
 * @root: the pointer to binary heap
 */
void heapify(heap_t *root)
{
    int value;
    heap_t *tmp1, *tmp2;

    if (!root)
        return;

    tmp1 = root;

    while (1)
    {
        if (!tmp1->left)
            break;
        if (!tmp1->right)
            tmp2 = tmp1->left;
        else
        {
            if (tmp1->left->n > tmp1->right->n)
                tmp2 = tmp1->left;
            else
                tmp2 = tmp1->right;
        }
        if (tmp1->n > tmp2->n)
            break;
        value = tmp1->n;
        tmp1->n = tmp2->n;
        tmp2->n = value;
        tmp1 = tmp2;
    }
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
    int value;
    heap_t *heap_R, *node;

    if (!root || !*root)
        return (0);
    heap_R = *root;
    value = heap_R->n;
    if (!heap_R->left && !heap_R->right)
    {
        *root = NULL;
        free(heap_R);
        return (value);
    }

    _pre_order(heap_R, &node, tree_height(heap_R));

    heap_R->n = node->n;
    if (node->parent->right)
        node->parent->right = NULL;
    else
        node->parent->left = NULL;
    free(node);
    heapify(heap_R);
    *root = heap_R;
    return (value);
}