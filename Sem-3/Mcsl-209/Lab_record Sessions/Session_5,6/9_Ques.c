// Q9. Write a program in C language that accepts two singly linked lists A and B as input and prints a singly linked list containing
//     only the elements common to both A and B.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(int n)
{
    struct Node *head = NULL, *tail = NULL, *newNode;
    int i;

    for (i = 0; i < n; i++)
    {
        newNode = malloc(sizeof(struct Node));
        if (newNode == NULL)
            exit(1);

        printf("Enter value: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main(void)
{
    struct Node *A, *B, *p, *q;
    int n, m, found, alreadyPrinted;

    printf("Number of elements in A: ");
    scanf("%d", &n);
    A = createList(n);

    printf("Number of elements in B: ");
    scanf("%d", &m);
    B = createList(m);

    printf("Common elements: ");

    for (p = A; p != NULL; p = p->next)
    {
        found = 0;
        alreadyPrinted = 0;

        for (q = B; q != NULL; q = q->next)
        {
            if (p->data == q->data)
            {
                found = 1;
                break;
            }
        }

        for (q = A; q != p; q = q->next)
        {
            if (q->data == p->data)
            {
                alreadyPrinted = 1;
                break;
            }
        }

        if (found && !alreadyPrinted)
            printf("%d ", p->data);
    }

    printf("\n");
    return 0;
}
