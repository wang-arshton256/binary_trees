#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
#define INIT_NODE           \
    {                       \
        0, NULL, NULL, NULL \
    }

/**
 * swap - swaps the two nodes in the binary tree
 * @a: the first node
 * @b: the second node
 * Return: the pointer to root
 */
bst_t *swap(bst_t *a, bst_t *b)
{
    bst_t a_Copy = INIT_NODE;

    a_Copy.n = a->n;
    a_Copy.parent = a->parent;
    a_Copy.left = a->left;
    a_Copy.right = a->right;
    a->parent = b;
    a->left = b->left;
    a->right = b->right;
    if (b->left)
        b->left->parent = a;
    if (b->right)
        b->right->parent = a;

    b->parent = a_Copy.parent;
    if (a_Copy.parent)
    {
        if (a == a_Copy.parent->left)
            a_Copy.parent->left = b;
        else
            a_Copy.parent->right = b;
    }
    if (b == a_Copy.left)
    {
        b->left = a;
        b->right = a_Copy.right;
        if (a_Copy.right)
            a_Copy.right->parent = b;
    }
    else if (b == a_Copy.right)
    {
        b->right = a;
        b->left = a_Copy.left;
        if (a_Copy.left)
            a_Copy.left->parent = b;
    }
    while (b->parent)
        b = b->parent;
    return (b);
}

/**
 * convert - converts the number and the base into string
 * @num: the number to input
 * @base: the nput base to input
 * @lowercase: flag if hexa values, need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
    static char *rep;
    static char buffer[50];
    char *ptr;

    rep = (lowercase)
              ? "0123456789abcdef"
              : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = 0;
    do
    {
        *--ptr = rep[num % base];
        num /= base;
    } while (num);

    return (ptr);
}

/**
 * binary_tree_size - calculates the size of the binary tree
 * @tree: the input binary tree
 * Return: the number of descendant child nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * insert - helper func for inserting node to correct location
 * @root: A double pointer to the root of max heap
 * @node: A node to insert
 */
void insert(heap_t **root, heap_t *node)
{
    heap_t *tmp;
    int size;
    unsigned int i;
    char *binary;
    char c;

    tmp = *root;
    size = binary_tree_size(tmp) + 1;
    binary = convert(size, 2, 1);
    for (i = 1; i < strlen(binary); i++)
    {
        c = binary[i];
        if (i == strlen(binary) - 1)
        {
            if (c == '1')
            {
                node->parent = tmp;
                tmp->right = node;
                break;
            }
            else if (c == '0')
            {
                node->parent = tmp;
                tmp->left = node;
                break;
            }
        }
        if (c == '1')
            tmp = tmp->right;
        else if (c == '0')
            tmp = tmp->left;
    }
}

/**
 * heap_insert - inserts the value into a Max Binary Heap
 * @root: the double pointer  the to root of the tree
 * @value: the input value
 * Return: the pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *hyt = NULL, *ret;

    if (!root)
        return (NULL);
    hyt = calloc(1, sizeof(heap_t));
    hyt->n = value;
    if (!*root)
    {
        *root = hyt;
        return (hyt);
    }
    insert(root, hyt);
    while (hyt->parent && hyt->n > hyt->parent->n)
    {
        ret = swap(hyt->parent, hyt);
        if (ret)
            *root = ret;
    }
    return (hyt);
}