#include "binary_trees.h"

/**
 * tree_size - calculates the sum of the heights of a binary tree
 * @tree: the pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
    size_t height_L = 0;
    size_t height_R = 0;

    if (!tree)
        return (0);

    if (tree->left)
        height_L = 1 + tree_size(tree->left);

    if (tree->right)
        height_R = 1 + tree_size(tree->right);

    return (height_L + height_R);
}

/**
 * heap_to_sorted_array - converts the Binary to a Max Heap
 * to a sorted array of integers
 *
 * @heap: the pointer to the root node of the heap to be converted
 * @size: the address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int i, *a = NULL;

    if (!heap || !size)
        return (NULL);

    *size = tree_size(heap) + 1;

    a = malloc(sizeof(int) * (*size));

    if (!a)
        return (NULL);

    for (i = 0; heap; i++)
        a[i] = heap_extract(&heap);

    return (a);
}