#include "binary_trees.h"

/**
 * bal - calculates the balance factor of a AVL
 * @tree: the tree to go through
 * Return: the balanced factor
 */
void bal(avl_t **tree)
{
    int b_val;

    if (tree == NULL || *tree == NULL)
        return;
    if ((*tree)->left == NULL && (*tree)->right == NULL)
        return;
    bal(&(*tree)->left);
    bal(&(*tree)->right);
    b_val = binary_tree_balance((const binary_tree_t *)*tree);
    if (b_val > 1)
        *tree = binary_tree_rotate_right((binary_tree_t *)*tree);
    else if (b_val < -1)
        *tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - gets the next successor ,the min node in the right subtree
 * @node: tree to be checked
 * Return: min value of this tree
 */
int successor(bst_t *node)
{
    int left = 0;

    if (node == NULL)
    {
        return (0);
    }
    else
    {
        left = successor(node->left);
        if (left == 0)
        {
            return (node->n);
        }
        return (left);
    }
}
/**
 *remove_type - function which removes node depending of its children
 *@root: node to be removed
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
    int new_Val = 0;

    if (!root->left && !root->right)
    {
        if (root->parent->right == root)
            root->parent->right = NULL;
        else
            root->parent->left = NULL;
        free(root);
        return (0);
    }
    else if ((!root->left && root->right) || (!root->right && root->left))
    {
        if (!root->left)
        {
            if (root->parent->right == root)
                root->parent->right = root->right;
            else
                root->parent->left = root->right;
            root->right->parent = root->parent;
        }
        if (!root->right)
        {
            if (root->parent->right == root)
                root->parent->right = root->left;
            else
                root->parent->left = root->left;
            root->left->parent = root->parent;
        }
        free(root);
        return (0);
    }
    else
    {
        new_Val = successor(root->right);
        root->n = new_Val;
        return (new_Val);
    }
}
/**
 * bst_remove - removeS the node from a BST tree
 * @root: the root of the tree
 * @value: node with value to be removed
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
    int type = 0;

    if (root == NULL)
        return (NULL);
    if (value < root->n)
        bst_remove(root->left, value);
    else if (value > root->n)
        bst_remove(root->right, value);
    else if (value == root->n)
    {
        type = remove_type(root);
        if (type != 0)
            bst_remove(root->right, type);
    }
    else
        return (NULL);
    return (root);
}

/**
 * avl_remove - removes the node from a AVL tree
 * @root: the root of the tree
 * @value: the node with value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *root_w = (avl_t *)bst_remove((bst_t *)root, value);

    if (root_w == NULL)
        return (NULL);
    bal(&root_w);
    return (root_w);
}