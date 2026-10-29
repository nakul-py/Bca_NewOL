// Q24. Write a program in C language to count the number of leaves of a binary tree.

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

int countLeaves(struct Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) +
           countLeaves(root->right);
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

    printf("Number of leaf nodes: %d\n",
           countLeaves(root));

    return 0;
}
