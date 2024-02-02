#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *_insert_avl_recursive(avl_t **tree, avl_t *parent,
                             avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
    if (tree != NULL)
    {
        size_t l = 0, r = 0;

        l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
        r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
        return ((l > r) ? l : r);
    }
    return (0);
}

/**
 * balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
    return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * _insert_avl_recursive - recursively inserts a value into the AVL tree .
 * @tree: double pointer to the root node of the AVL tree to insert into.
 * @parent: parent node of the currently working node.
 * @new: double pointer to store a new node.
 * @value: value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *_insert_avl_recursive(avl_t **tree, avl_t *parent,
                             avl_t **new, int value)
{
    int be_facto;

    if (*tree == NULL)
        return (*new = binary_tree_node(parent, value));

    if ((*tree)->n > value)
    {
        (*tree)->left = _insert_avl_recursive(&(*tree)->left, *tree, new, value);
        if ((*tree)->left == NULL)
            return (NULL);
    }
    else if ((*tree)->n < value)
    {
        (*tree)->right = _insert_avl_recursive(&(*tree)->right, *tree, new, value);
        if ((*tree)->right == NULL)
            return (NULL);
    }
    else
        return (*tree);

    be_facto = balance(*tree);
    if (be_facto > 1 && (*tree)->left->n > value)
        *tree = binary_tree_rotate_right(*tree);
    else if (be_facto < -1 && (*tree)->right->n < value)
        *tree = binary_tree_rotate_left(*tree);
    else if (be_facto > 1 && (*tree)->left->n < value)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        *tree = binary_tree_rotate_right(*tree);
    }
    else if (be_facto < -1 && (*tree)->right->n > value)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        *tree = binary_tree_rotate_left(*tree);
    }

    return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new = NULL;

    if (tree == NULL)
        return (NULL);
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }
    _insert_avl_recursive(tree, *tree, &new, value);
    return (new);
}