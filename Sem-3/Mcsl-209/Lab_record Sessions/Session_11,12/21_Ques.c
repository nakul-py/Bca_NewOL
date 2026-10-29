// Q21. Write a program in C language to accept a tree as input, convert it into a binary tree, and print the resultant binary tree.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *nodes[100];
int count = 0;

struct Node *getNode(int x)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (nodes[i]->data == x)
            return nodes[i];
    }

    nodes[count] = malloc(sizeof(struct Node));
    if (nodes[count] == NULL)
        exit(1);

    nodes[count]->data = x;
    nodes[count]->left = NULL;
    nodes[count]->right = NULL;

    return nodes[count++];
}

void printTree(void)
{
    int i;

    printf("\nBinary tree representation:\n");

    for (i = 0; i < count; i++)
    {
        printf("Node %d: Left child = ", nodes[i]->data);

        if (nodes[i]->left != NULL)
            printf("%d", nodes[i]->left->data);
        else
            printf("NULL");

        printf(", Right sibling = ");

        if (nodes[i]->right != NULL)
            printf("%d", nodes[i]->right->data);
        else
            printf("NULL");

        printf("\n");
    }
}

int main(void)
{
    int rootValue, edges, parent, child, i;
    struct Node *p, *c, *temp;

    printf("Enter root value: ");
    scanf("%d", &rootValue);
    getNode(rootValue);

    printf("Enter number of parent-child pairs: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++)
    {
        printf("Enter parent and child: ");
        scanf("%d %d", &parent, &child);

        p = getNode(parent);
        c = getNode(child);

        if (p->left == NULL)
        {
            p->left = c;
        }
        else
        {
            temp = p->left;

            while (temp->right != NULL)
                temp = temp->right;

            temp->right = c;
        }
    }

    printTree();
    return 0;
}
