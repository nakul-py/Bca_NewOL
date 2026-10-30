// Question 38- Write a program in C language to insert the following values into an initially empty Splay tree: 15, 25, 2, 4, 3, 1, 50.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int key)
{
    struct Node *node = malloc(sizeof(struct Node));

    if (node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->data = key;
    node->left = node->right = NULL;
    return node;
}

struct Node *rightRotate(struct Node *x)
{
    struct Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

/* Move the required key to the root */
struct Node *splay(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
    {
        if (root->left == NULL)
            return root;

        /* Zig-Zig case */
        if (key < root->left->data)
        {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        /* Zig-Zag case */
        else if (key > root->left->data)
        {
            root->left->right = splay(root->left->right, key);

            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    else
    {
        if (root->right == NULL)
            return root;

        /* Zag-Zag case */
        if (key > root->right->data)
        {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        /* Zag-Zig case */
        else if (key < root->right->data)
        {
            root->right->left = splay(root->right->left, key);

            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

struct Node *insert(struct Node *root, int key)
{
    struct Node *node;

    if (root == NULL)
        return newNode(key);

    root = splay(root, key);

    if (root->data == key)
        return root; /* Ignore duplicates */

    node = newNode(key);

    if (key < root->data)
    {
        node->right = root;
        node->left = root->left;
        root->left = NULL;
    }
    else
    {
        node->left = root;
        node->right = root->right;
        root->right = NULL;
    }

    return node;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(void)
{
    struct Node *root = NULL;
    int values[] = {15, 25, 2, 4, 3, 1, 50};
    int n = sizeof(values) / sizeof(values[0]);
    int i;

    for (i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nRoot of Splay tree: %d\n", root->data);

    return 0;
}
