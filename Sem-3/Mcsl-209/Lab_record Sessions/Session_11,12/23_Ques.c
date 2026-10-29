// Q23. Write a program in C language to accept two trees as input and check whether both trees are the same. Display the appropriate message.

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

int sameTree(struct Node *a, struct Node *b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    return a->data == b->data &&
           sameTree(a->left, b->left) &&
           sameTree(a->right, b->right);
}

int main(void)
{
    struct Node *a = NULL, *b = NULL;
    int n, m, x, i;

    printf("Enter number of nodes in tree 1: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &x);
        a = insert(a, x);
    }

    printf("Enter number of nodes in tree 2: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        printf("Enter value: ");
        scanf("%d", &x);
        b = insert(b, x);
    }

    if (sameTree(a, b))
        printf("Both trees are the same\n");
    else
        printf("Both trees are not the same\n");

    return 0;
}
