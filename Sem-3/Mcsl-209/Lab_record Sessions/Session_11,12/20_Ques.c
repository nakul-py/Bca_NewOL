// Q20. Write a program in C language to perform preorder, postorder, and inorder traversals of a binary tree without using recursion.

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

void preorder(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;

    if (root != NULL)
        stack[++top] = root;

    while (top != -1)
    {
        struct Node *p = stack[top--];
        printf("%d ", p->data);

        if (p->right != NULL)
            stack[++top] = p->right;
        if (p->left != NULL)
            stack[++top] = p->left;
    }
}

void inorder(struct Node *root)
{
    struct Node *stack[100];
    struct Node *p = root;
    int top = -1;

    while (p != NULL || top != -1)
    {
        while (p != NULL)
        {
            stack[++top] = p;
            p = p->left;
        }

        p = stack[top--];
        printf("%d ", p->data);
        p = p->right;
    }
}

void postorder(struct Node *root)
{
    struct Node *s1[100], *s2[100];
    int top1 = -1, top2 = -1;

    if (root != NULL)
        s1[++top1] = root;

    while (top1 != -1)
    {
        struct Node *p = s1[top1--];
        s2[++top2] = p;

        if (p->left != NULL)
            s1[++top1] = p->left;
        if (p->right != NULL)
            s1[++top1] = p->right;
    }

    while (top2 != -1)
        printf("%d ", s2[top2--]->data);
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

    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");
    return 0;
}
