#include "binary_trees.h"

/**
 * createTree - creates an AVL tree with recursion
 *
 * @node:the pointer node
 * @array: the input array of integers
 * @size: the size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void createTree(avl_t **node, int *array, size_t size, int mode)
{
    size_t middle;

    if (size == 0)
        return;

    middle = (size / 2);
    middle = (size % 2 == 0) ? middle - 1 : middle;

    if (mode == 1)
    {
        (*node)->left = binary_tree_node(*node, array[middle]);
        createTree(&((*node)->left), array, middle, 1);
        createTree(&((*node)->left), array + middle + 1, (size - 1 - middle), 2);
    }
    else
    {
        (*node)->right = binary_tree_node(*node, array[middle]);
        createTree(&((*node)->right), array, middle, 1);
        createTree(&((*node)->right), array + middle + 1, (size - 1 - middle), 2);
    }
}

/**
 * sorted_array_to_avl - creates root node and calls to createTree function
 *
 * @array: the input array of integers
 * @size: the size of array
 * Return: the pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *root;
    size_t middle;

    root = NULL;

    if (size == 0)
        return (NULL);

    middle = (size / 2);

    middle = (size % 2 == 0) ? middle - 1 : middle;

    root = binary_tree_node(root, array[middle]);

    createTree(&root, array, middle, 1);
    createTree(&root, array + middle + 1, (size - 1 - middle), 2);

    return (root);
}