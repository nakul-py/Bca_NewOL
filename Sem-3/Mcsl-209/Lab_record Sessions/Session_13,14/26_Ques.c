// Question 26- Write a program in C language to insert the following values into an initially empty AVL tree: 15, 25, 2, 4, 3, 1, 50. Make assumptions, if necessary.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *left, *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct Node *newNode(int x)
{
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL)
        exit(1);

    n->data = x;
    n->height = 1;
    n->left = n->right = NULL;

    return n;
}

/* Right rotation */
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

/* Left rotation */
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

/* Insert a value into AVL tree */
struct Node *insert(struct Node *root, int x)
{
    int balance;

    if (root == NULL)
        return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    else
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    balance = height(root->left) - height(root->right);

    /* LL Case */
    if (balance > 1 && x < root->left->data)
        return rightRotate(root);

    /* RR Case */
    if (balance < -1 && x > root->right->data)
        return leftRotate(root);

    /* LR Case */
    if (balance > 1 && x > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    /* RL Case */
    if (balance < -1 && x < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(void)
{
    struct Node *root = NULL;
    int values[] = {15, 25, 2, 4, 3, 1, 50};
    int i;

    for (i = 0; i < 7; i++)
    {
        root = insert(root, values[i]);
    }

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");

    return 0;
}
