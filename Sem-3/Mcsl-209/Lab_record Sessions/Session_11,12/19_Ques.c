// Q19. Write a program in C language to create a binary tree and implement insertion and deletion operations.


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

struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node *deleteNode(struct Node *root, int x)
{
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
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

    printf("Tree (inorder): ");
    inorder(root);

    printf("\nEnter value to insert: ");
    scanf("%d", &x);
    root = insert(root, x);

    printf("After insertion: ");
    inorder(root);

    printf("\nEnter value to delete: ");
    scanf("%d", &x);
    root = deleteNode(root, x);

    printf("After deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
