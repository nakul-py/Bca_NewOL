// Question 40- Write a program in C language to create an AA-tree and implement insertion and deletion operations.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int level;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = malloc(sizeof(struct Node));

    if (node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->data = data;
    node->level = 1;
    node->left = node->right = NULL;

    return node;
}

/* Right rotation to remove a left horizontal link */
struct Node *skew(struct Node *root)
{
    struct Node *leftChild;

    if (root == NULL || root->left == NULL)
        return root;

    if (root->left->level == root->level)
    {
        leftChild = root->left;
        root->left = leftChild->right;
        leftChild->right = root;
        return leftChild;
    }

    return root;
}

/* Left rotation to remove consecutive right horizontal links */
struct Node *split(struct Node *root)
{
    struct Node *rightChild;

    if (root == NULL || root->right == NULL ||
        root->right->right == NULL)
        return root;

    if (root->level == root->right->right->level)
    {
        rightChild = root->right;
        root->right = rightChild->left;
        rightChild->left = root;
        rightChild->level++;
        return rightChild;
    }

    return root;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root; /* Ignore duplicates */

    root = skew(root);
    root = split(root);

    return root;
}

int getLevel(struct Node *node)
{
    return node == NULL ? 0 : node->level;
}

/* Find the smallest node */
struct Node *minimum(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

/* Find the largest node */
struct Node *maximum(struct Node *root)
{
    while (root->right != NULL)
        root = root->right;

    return root;
}

struct Node *deleteNode(struct Node *root, int data)
{
    int shouldBe;

    if (root == NULL)
        return NULL;

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        /* Node has no children */
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        /* Replace with predecessor */
        else if (root->left != NULL)
        {
            struct Node *pred = maximum(root->left);
            root->data = pred->data;
            root->left = deleteNode(root->left, pred->data);
        }
        /* Replace with successor */
        else
        {
            struct Node *succ = minimum(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }

    /* Decrease the level if necessary */
    shouldBe = getLevel(root->left);
    if (getLevel(root->right) < shouldBe)
        shouldBe = getLevel(root->right);

    shouldBe++;

    if (shouldBe < root->level)
    {
        root->level = shouldBe;

        if (root->right != NULL &&
            root->right->level > shouldBe)
            root->right->level = shouldBe;
    }

    /* Restore AA-tree properties */
    root = skew(root);

    if (root->right != NULL)
        root->right = skew(root->right);

    if (root->right != NULL && root->right->right != NULL)
        root->right->right = skew(root->right->right);

    root = split(root);

    if (root->right != NULL)
        root->right = split(root->right);

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

int search(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return 1;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

int main(void)
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);

            if (search(root, value))
            {
                root = deleteNode(root, value);
                printf("Value deleted successfully\n");
            }
            else
            {
                printf("Value not found\n");
            }
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);

            if (search(root, value))
                printf("Value found\n");
            else
                printf("Value not found\n");
            break;

        case 4:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
