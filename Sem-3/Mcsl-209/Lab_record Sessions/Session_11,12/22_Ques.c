// Q22. Write a program in C language to accept a binary tree as input and check whether it is a full binary tree.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, int x)
{
    if (root == NULL)
    {
        struct Node *n = malloc(sizeof(struct Node));
        if (n == NULL)
            exit(1);
        n->data = x;
        n->left = n->right = NULL;
        return n;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

int isFull(struct Node *root)
{
    if (root == NULL)
        return 1;

    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->left != NULL && root->right != NULL)
        return isFull(root->left) && isFull(root->right);

    return 0;
}

int main(void)
{
    struct Node *root = NULL;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &x);
        root = insert(root, x);
    }

    if (isFull(root))
        printf("The tree is a full binary tree\n");
    else
        printf("The tree is not a full binary tree\n");

    return 0;
}
