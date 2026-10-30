// Question 25- Write a program in C language to create a binary search tree (BST), accept a key value, search for it in the BST, and print the appropriate message.

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
        struct Node *newNode = malloc(sizeof(struct Node));
        if (newNode == NULL)
            exit(1);

        newNode->data = x;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

int search(struct Node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main(void)
{
    struct Node *root = NULL;
    int n, x, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("%d is found in the BST\n", key);
    else
        printf("%d is not found in the BST\n", key);

    return 0;
}
