// Question 39- Write a program in C language to create a Red-Black tree and implement insertion and deletion operations.

#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

struct Node
{
    int data, color;
    struct Node *left, *right, *parent;
};

struct Node *root;
struct Node *NIL;

struct Node *newNode(int data)
{
    struct Node *node = malloc(sizeof(struct Node));

    if (node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = NIL;

    return node;
}

void leftRotate(struct Node *x)
{
    struct Node *y = x->right;

    x->right = y->left;

    if (y->left != NIL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(struct Node *y)
{
    struct Node *x = y->left;

    y->left = x->right;

    if (x->right != NIL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NIL)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;

    x->right = y;
    y->parent = x;
}

void insertFix(struct Node *z)
{
    struct Node *y;

    while (z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;

            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        }
        else
        {
            y = z->parent->parent->left;

            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

void insert(int data)
{
    struct Node *z = newNode(data);
    struct Node *y = NIL;
    struct Node *x = root;

    while (x != NIL)
    {
        y = x;

        if (data < x->data)
            x = x->left;
        else if (data > x->data)
            x = x->right;
        else
        {
            free(z);
            printf("Duplicate value ignored\n");
            return;
        }
    }

    z->parent = y;

    if (y == NIL)
        root = z;
    else if (data < y->data)
        y->left = z;
    else
        y->right = z;

    insertFix(z);
}

struct Node *minimum(struct Node *node)
{
    while (node->left != NIL)
        node = node->left;

    return node;
}

void transplant(struct Node *u, struct Node *v)
{
    if (u->parent == NIL)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    v->parent = u->parent;
}

void deleteFix(struct Node *x)
{
    struct Node *w;

    while (x != root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            w = x->parent->right;

            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }

            if (w->left->color == BLACK &&
                w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        }
        else
        {
            w = x->parent->left;

            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }

            if (w->right->color == BLACK &&
                w->left->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }

    x->color = BLACK;
}

void deleteNode(int data)
{
    struct Node *z = root;
    struct Node *y, *x;
    int originalColor;

    while (z != NIL && z->data != data)
    {
        if (data < z->data)
            z = z->left;
        else
            z = z->right;
    }

    if (z == NIL)
    {
        printf("Value not found\n");
        return;
    }

    y = z;
    originalColor = y->color;

    if (z->left == NIL)
    {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == NIL)
    {
        x = z->left;
        transplant(z, z->left);
    }
    else
    {
        y = minimum(z->right);
        originalColor = y->color;
        x = y->right;

        if (y->parent == z)
            x->parent = y;
        else
        {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    free(z);

    if (originalColor == BLACK)
        deleteFix(x);
}

void inorder(struct Node *node)
{
    if (node != NIL)
    {
        inorder(node->left);
        printf("%d(%s) ", node->data,
               node->color == RED ? "R" : "B");
        inorder(node->right);
    }
}

int main(void)
{
    int choice, value;

    NIL = malloc(sizeof(struct Node));
    if (NIL == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = NIL;
    root = NIL;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;

        case 3:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
